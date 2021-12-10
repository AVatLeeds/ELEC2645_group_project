#include "line_editor.h"
#include <iostream>
#include <string>
#include <list>
#include <map>
#include "tokenizer.h"

enum line_type {EXPRESSION, COMMAND_SEQUENCE};

struct line_section
{
	enum line_type type;
	std::string line;
};

void print_token_list(std::list<struct token_list_node> list)
{
	std::list<struct token_list_node>::iterator list_iter = list.begin();
	while (list_iter != list.end())
	{
		switch (list_iter->is)
		{
			case COMMAND_WORD:
			std::cout << list_iter->cmd_string << " -> ";
			break;

			case NUMBER:
			std::cout << list_iter->number << " -> ";
			break;

			case OPERATOR:
			switch (list_iter->op)
			{
				case ADD:
				std::cout << '+';
				break;

				case SUB:
				std::cout << '-';
				break;

				case MUL:
				std::cout << '*';
				break;

				case DIV:
				std::cout << '/';
				break;

				case POW:
				std::cout << '^';
				break;
			
				default:
				break;
			}
			std::cout << " -> ";
			break;

			case SEPARATOR:
			switch (list_iter->sep)
			{
				case OPEN_EXPRESSION:
				std::cout << '(';
				break;

				case CLOSE_EXPRESSION:
				std::cout << ')';
				break;

				case OPEN_COMMAND:
				std::cout << '[';
				break;

				case CLOSE_COMMAND:
				std::cout << ']';
				break;
			
				default:
				break;
			}
			std::cout << " -> ";
			break;

			default:
			break;
		}		
		list_iter ++;
	}
	std::cout << std::endl;
}

unsigned int tokenize_RP(std::string line, std::list<struct token_list_node> * token_list)
{
	unsigned int i = 0;
	std::size_t length;

	struct token_list_node node;

	while (i < line.length())
	{
		if (isdigit(line[i]) || (line[i] == '-') || (line[i] == '+'))
		{
			node.is = NUMBER;
			try
			{
				node.number = std::stod(&line[i], &length);
			}
			catch (const std::invalid_argument & error)
			{
				std::cerr << "Error: Malformed number." << std::endl;
				return 0;
			}
			catch (const std::out_of_range & error)
			{
				std::cerr << "Error: Number out of range." << std::endl;
				return 0;
			}
			token_list->push_back(node);
			i += length;
		}
		else if (isalpha(line[i]) || (line[i] == '_'))
		{
			node.is = COMMAND_WORD;
			node.cmd_string.clear();
			node.cmd_string.append({line[i]});
			i ++;
			while((isalpha(line[i]) || isdigit(line[i]) || (line[i] == '_')) && (i < line.length()))
			{
				node.cmd_string.append({line[i]});
				i ++;
			}
			token_list->push_back(node);
		}
		else
		{
			switch (line[i])
			{
				case ' ':
				i ++;
				break;

				default:
				std::cerr << "Error: unidentified character " << line[i] << std::endl;
				return 0;
			}
		}
	}
	return 1;
}

unsigned int tokenize_infix(std::string line, std::list<struct token_list_node> * token_list)
{
	unsigned int i = 0;
	std::size_t length;

	struct token_list_node node;

	while (i < line.length())
	{
		if (isdigit(line[i]) || (line[i] == '-') || (line[i] == '+'))
		{
			node.is = NUMBER;
			try
			{
				node.number = std::stod(&line[i], &length);
			}
			catch (const std::invalid_argument & error)
			{
				if (line[i] == '+')
				{
					node.is = OPERATOR;
					node.op = ADD;
					length = 1;
				}
				else if (line[i] == '-')
				{
					node.is = OPERATOR;
					node.op = SUB;
					length = 1;
				}
				else
				{
					std::cerr << "Error: Malformed number." << std::endl;
					return 0;
				}
				
			}
			catch (const std::out_of_range & error)
			{
				std::cerr << "Error: Number out of range." << std::endl;
				return 0;
			}
			token_list->push_back(node);
			i += length;
		}
		else
		{
			switch (line[i])
			{
				case '*':
				node.is = OPERATOR;
				node.op = MUL;
				token_list->push_back(node);
				i++;
				break;

				case '/':
				node.is = OPERATOR;
				node.op = DIV;
				token_list->push_back(node);
				i++;
				break;

				case '^':
				node.is = OPERATOR;
				node.op = POW;
				token_list->push_back(node);
				i++;
				break;

				case '(':
				node.is = SEPARATOR;
				node.sep = OPEN_EXPRESSION;
				token_list->push_back(node);
				i++;
				break;

				case ')':
				node.is = SEPARATOR;
				node.sep = CLOSE_EXPRESSION;
				token_list->push_back(node);
				i++;
				break;

				case ' ':
				i ++;
				break;
			
				default:
				std::cerr << "Error: unidentified character " << line[i] << std::endl;
				return 0;
			}
		}
	}
	return 1;
}

unsigned int tokenize(std::string line, std::list<struct token_list_node> * token_list)
{
	unsigned int i;
	int bracket_count = 0;

	struct line_section line_section;
	line_section.type = COMMAND_SEQUENCE;

	std::list<struct line_section> line_sections;
	
	for (i = 0; i < line.length(); i ++)
	{
		line_section.line.append({line[i]});

		if (line[i] == '(')
		{
			if (!bracket_count)
			{
				line_section.line.pop_back();
				if (i && !line_section.line.empty())
				{
					line_sections.push_back(line_section);
					line_section.line.clear();
				}
				line_section.type = EXPRESSION;
			}
			bracket_count ++;
		}
		if (line[i] == ')')
		{
			bracket_count --;
			if (bracket_count == 0)
			{
				line_section.line.pop_back();
				line_sections.push_back(line_section);
				line_section.line.clear();
				line_section.type = COMMAND_SEQUENCE;
			}
		}
	}

	if (bracket_count > 0)
	{
		std::cerr << "Error: Missing closing bracket in mathematical expression." << std::endl;
		return 0;
	}
	else if (bracket_count < 0)
	{
		std::cerr << "Error: Missing opening bracket in mathematical expression." << std::endl;
		return 0;
	}
	else if (!line_section.line.empty())
	{
		line_sections.push_back(line_section);
	}

	std::list<struct line_section>::iterator line_sections_iter = line_sections.begin();
	while (line_sections_iter != line_sections.end())
	{
		switch (line_sections_iter->type)
		{
			case EXPRESSION:
			if (!tokenize_infix(line_sections_iter->line, token_list))
			{
				return 0;
			}
			break;

			case COMMAND_SEQUENCE:
			if (!tokenize_RP(line_sections_iter->line, token_list))
			{
				return 0;
			}
			break;
		}
		line_sections_iter ++;
	}
	return 1;
}

/*
unsigned int match_only_word(std::string in_string, std::string to_match)
{
	unsigned int i;
	if (to_match.length() > in_string.length())
	{
		return 0;
	}
	for (i = 0; i < to_match.length(); i ++)
	{
		if (to_match[i] != in_string[i])
		{
			return 0;
		}
	}
	if ((i == in_string.length()) || !isalpha(in_string[i]))
	{
		return i;
	}
	return 0;
}

unsigned int find_numbers(std::string command_line, std::list<struct token_list_node> * token_list, unsigned int start_idx)
{
	unsigned int i = 0;
	struct token_list_node node;
	node.is = NUMBER;
	std::size_t chars_processed;
	
	while (i < command_line.length())
	{
		if (isdigit(command_line[i]) || (command_line[i] == '+') || (command_line[i] == '-'))
		{
			node.index = i;
			try
			{
				node.number = std::stod(&command_line[i], &chars_processed);
				node.length = chars_processed;
				i += (node.length + 1);
				node.literal_string = command_line.substr(node.index, node.length); // for debug only
				node.index += start_idx;
				token_list->push_back(node);
				if (find_numbers(command_line.substr(i), token_list, i + start_idx))
				{
					return 1;
				}
				return 0;
			}
			catch (const std::invalid_argument * error)
			{
				std::cerr << "Error: Malformed number." << std::endl;
			}
			catch (const std::out_of_range * error)
			{
				std::cerr << "Error: Number out of range." << std::endl;
			}
		}
		i++;
	}
	return 1;
}

unsigned int find_command_words(std::string command_line, std::list<struct token_list_node> * token_list, unsigned int start_idx)
{
	unsigned int i = 0;
	std::map<std::string, struct command_info>::iterator cmd_map_iter;
	struct token_list_node node;
	node.is = COMMAND_WORD;
	unsigned int length;
	node.length = 0;
		
	// traverse to first alphabetic character
	while ((i < command_line.length()) && !isalpha(command_line[i]))
	{
		i ++;
	}
	if (i == command_line.length())
	{
		return 1;
	}
	node.index = i;
	// iterate over the command words
	for (cmd_map_iter = command_map.begin(); cmd_map_iter != command_map.end(); cmd_map_iter ++)
	{
		//attempt to find largest matching command word at this index
		length = match_only_word(command_line.substr(i), cmd_map_iter->first); // first accesses the first value in the pair at the iterator, which is the key
		if (length > node.length)
		{
			node.length = length;
			node.cmd_word = cmd_map_iter->second;
		}
	}
	i += (node.length + 1);
	// couldn't find any command words here
	if (node.length == 0)
	{
		while ((i < command_line.length()) && isalpha(command_line[i]))
        {
            i ++;
        }
		std::cerr << "Error: Unrecognised command word " << command_line.substr(node.index, (i - node.index)) << std::endl;
        return 0;
	}
	// largest possible command word found
	else
	{
		node.literal_string = command_line.substr(node.index, (node.length + 1)); // for debug only
		node.index += start_idx;
		token_list->push_back(node);
		if (find_command_words(command_line.substr(i), token_list, i + start_idx))
		{
			return 1;
		}
		return 0;
	} 
}

unsigned int find_number(std::string line, std::list<struct token_list_node> * token_list)
{
	struct token_list_node node;
	node.is = NUMBER;
	std::size_t chars_processed;
	
	try
	{
		node.number = std::stod(&line[0], &chars_processed);
		node.length = chars_processed;
		node.literal_string = line.substr(0, node.length); // for debug only
		token_list->push_back(node);
	}
	catch (const std::invalid_argument * error)
	{
		std::cerr << "Error: Malformed number." << std::endl;
	}
	catch (const std::out_of_range * error)
	{
		std::cerr << "Error: Number out of range." << std::endl;
	}

	return node.length;
}

unsigned int find_command_word(std::string line, std::list<struct token_list_node> * token_list)
{
	unsigned int i = 0;
	std::map<std::string, struct command_info>::iterator cmd_map_iter;
	struct token_list_node node;
	node.is = COMMAND_WORD;
	unsigned int length;
	node.length = 0;
	
	for (cmd_map_iter = command_map.begin(); cmd_map_iter != command_map.end(); cmd_map_iter ++)
	{
		//attempt to find largest matching command word at this index
		length = match_only_word(line, cmd_map_iter->first); // first accesses the first value in the pair at the iterator, which is the key
		if (length > node.length)
		{
			node.length = length;
			node.cmd_word = cmd_map_iter->second;
		}
	}
	// couldn't find any command words here
	if (node.length == 0)
	{
		while ((i < line.length()) && isalpha(line[i]))
        {
            i ++;
        }
		std::cerr << "Error: Unrecognised command word " << line.substr(0, i) << std::endl;
        return 0;
	}
	// largest possible command word found
	else
	{
		node.literal_string = line.substr(0, (node.length + 1)); // for debug only
		token_list->push_back(node);
		return node.length;
	} 
}
*/
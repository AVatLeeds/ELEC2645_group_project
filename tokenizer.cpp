#include "line_editor.h"
#include <iostream>
#include <string>
#include <list>
#include <map>
#include "tokenizer.h"
#include "functions_homogenised.h"

unsigned int find_numbers(std::string command_line, std::list<struct token_list_node> * token_list)
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
				token_list->push_back(node);
				if (find_numbers(command_line.substr(i + node.length + 1), token_list))
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
		return -- i;
	}
	return 0;
}

unsigned int find_command_words(std::string command_line, std::list<struct token_list_node> * token_list)
{
	unsigned int i = 0;
	std::map<std::string, struct command_info>::iterator cmd_map_iter;
	struct token_list_node node;
	node.is = COMMAND_WORD;
	unsigned int length;
	node.length = 0;
		
	// traverse to first alphabetic character
	while ((i < command_line.length()) && !isalpha(i))
	{
		i ++;
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
		token_list->push_back(node);
		find_command_words(command_line.substr(i), token_list);
		return 1;
	} 
}


/*
bool find_command_words(std::string command_line, std::list<struct token_list_node> * token_list)
{
	unsigned int i = 0;

	

	std::list<std::string>::iterator words_iter = command_words.begin();
		struct token_list_node node;
		unsigned int length;
		unsigned int greatest_length = 0;
		// this is CRUSTY. Please fix
		unsigned int index = 0;
		unsigned int index_of_greatest_length;
		
		// traverse to first alphabetic character
		while ((i < command_line.length()) && !isalpha(i))
		{
				i ++;
		}
		// iterate over the command words
		for (words_iter = command_words.begin(); words_iter != command_words.end(); words_iter ++)
		{
				//attempt to find largest matching command word at this index
				length = match_only_word(command_line.substr(i), *words_iter);
				if (length > greatest_length)
				{
						greatest_length = length;
						index_of_greatest_length = index;
				}
				index ++;
		}
		i += (greatest_length + 1);
		// couldn't find any command words here
		if (greatest_length = 0)
		{
				return 0;
		}
		// largest possible command word found
		else
		{
				node.is = COMMAND_WORD;
				node.length = greatest_length;
				node.command_word = (enum command_words)index;
				token_list->push_back(node);
				find_command_words(command_line.substr(i), token_list);
				return 1;
		} 
}

std::list<struct token_list_node> tokenize(std::string command_line)
{
		std::list<struct token_list_node> token_list;
		unsigned int i = 0;
		struct token_list_node node;

		while (command_line[i] == ' ')
		{
				i ++;
		}

		if (find_number(command_line.substr(i), &node))
		{
				token_list.push_back(node);
				i += node.lenght;
				i ++;
		}
		else if (find_command_word(command_line.substr(i), &node))
		{
				token_list.push_back(node);
				i += node.length;
				i ++;
		}



	std::string place_holder;

	int j = 0;
	std::list<struct Node>::iterator list_itr;
	list_itr = (*token_list).begin();
	//std::cout << command_line[0] << std::endl;

	for (int i=0 ; i<command_line.length() ; i++)
	{
		//std::cout << command_line[i] << std::endl;
		if ( command_line[i] == ' ' )
		{
			//std::cout << place_holder << std::endl;
			
			struct Node new_node;
			new_node.string = place_holder;
			place_holder.clear();
			(*token_list).push_back(new_node);
			*list_itr = new_node;
		}
		else
		{
			place_holder.append({command_line[i]});
		}
		
	}
	struct Node new_node;
	new_node.string = place_holder;
	place_holder.clear();
	(*token_list).push_back(new_node);

	for (list_itr = (*token_list).begin(); list_itr != (*token_list).end() ; list_itr ++)
	{ 
		std::cout << list_itr->string << std::endl;
		//peas
	}
}
*/
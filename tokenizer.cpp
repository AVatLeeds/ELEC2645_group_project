#include "line_editor.h"
#include <iostream>
#include <string>
#include <list>
#include "tokenizer.h"

enum token_type {SYMBOL, COMMAND_WORD, NUMBER, STRING, OPERATOR, SEPARATOR, COMMENT, UNMATCHED};

typedef enum {ADD, SUB, MUL, DIV, ABS, MOD, NOT, AND, OR, XOR, IF, FOR, DO, WHILE, DUP, SWAP, PUSH, POP, ROLL, PRINT, DEF} keyword_t;

std::list<std::string> command_words = {"add", "sub", "mul", "div", "abs", "mod", "not", "and", "or", "xor", "if", "for", "do", "while", "dup", "swap", "push", "pop", "roll", "print", "def"};

typedef enum {ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION, SQUARE, SQUARE_ROOT, EQUAL, UNEQUAL, LESS_THAN, GREATER_THAN,LESS_THAN_OR_EQUAL, GREATER_THAN_OR_EQUAL, OPEN_EXPRESSION, CLOSE_EXPRESSION, OPEN_BLOCK, CLOSE_BLOCK, SURPRESS} operator_t;
// things to add: arrays? assignment operator? bitwise logical operations? pointers?

std::list<std::string> operators = {"+", "-", "*", "/", "^", "_/", "=", "/=", "<", ">", "<=", ">=", "(", ")", "{", "}"};

typedef enum {SPACE, COMMA} separator_t;

struct token_list_node
{
  enum token_type is;
  unsigned int start;
  unsigned int end;
  std::string symbol;
  std::string command_word;
  double number;
  std::string string;
};


/******************************************************************************/
/**********STRINGS*************************************************************/
/******************************************************************************/
bool find_string(std::string command_line, struct token_list_node * token)
{
  unsigned int i = 0;
  token->string.clear();

	while (i < command_line.length())
  {
		if (command_line[i] == '\"')
    {
			token->start = i;
			i ++;
			while (i < command_line.length())
      {
				if (command_line[i] == '\"')
        {
					token->end = i;
					return 1;
				}
        token->string.append({command_line[i]});
				i ++;
			}
			std::cerr << "Error: String missing closing quote marks." << std::endl;
		}
		else if (command_line[i] == '\'')
    {
			token->start = i;
			i ++;
			while (i < command_line.length())
      {
				if (command_line[i] == '\'')
        {
					token->end = i;
					return 1;
				}
        token->string.append({command_line[i]});
				i ++;
			}
			std::cerr << "Error: String missing closing quote mark." << std::endl;
		}
		i ++;
	}
	return 0;
}

/******************************************************************************/
/**********NUMBERS***********************************************************/
/******************************************************************************/
bool find_number(std::string command_line, struct token_list_node * token)
{
	unsigned int i = 0;
  std::size_t chars_processed;
  
	while (i < command_line.length())
  {
    if (('0' <= command_line[i]) && (command_line[i] < '8'))
    {
      token->start = i;
      try
      {
        token->number = std::stod(&command_line[i], &chars_processed);
        token->end = i + chars_processed;
        return 1;
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
  }
  return 0;
}

void tokenize(std::string command_line, std::list<struct token_list_node> * token_list)
{
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

/******************************************************************************/
/**********KEYWORDS************************************************************/
/******************************************************************************/
/*
uint32_t find_keyword(file_char_t * in_buffer, token_t * token)
{
    uint32_t i = 0;
    file_char_t * start_ptr = in_buffer;
    file_char_t * found_ptr;
    uint32_t length = 0;
    uint32_t offset = 0xFFFFFFFF;
    uint32_t prev_length = 0;
    uint32_t prev_offset = 0xFFFFFFFF;
    uint32_t item = 0;
    token->is = KEYWORD;
    
    for (i = 0; i < NUM_KEYWORDS; i ++)
    {
        found_ptr = find_in_file(in_buffer, keywords[i], &length);
        if ((found_ptr != NULL) && (!isalpha((found_ptr + length)->value)))
        {
            offset = (found_ptr - start_ptr);
            if (offset < prev_offset)
            {
                item = i;
                prev_offset = offset;
                prev_length = length;
            }
            else if (offset == prev_offset)
            {
                if (length > prev_length)
                {
                    item = i;
                    prev_length = length;
                }
            }
        }
		length = 0;
    }
    if (offset == 0xFFFFFFFF)
    {
        return NOT_FOUND;
    }
    else
    {
        token->keyword = (keyword_t)item;
        populate_token(in_buffer, token, prev_offset, (prev_offset + prev_length));
        return SUCCESS;
    } 
}

/******************************************************************************/
/**********OPERATORS***********************************************************/
/******************************************************************************/
/*
uint32_t find_operator(file_char_t * in_buffer, token_t * token)
{
    uint32_t i = 0;
    file_char_t * start_ptr = in_buffer;
    file_char_t * found_ptr;
    uint32_t length = 0;
    uint32_t offset = 0xFFFFFFFF;
    uint32_t prev_length = 0;
    uint32_t prev_offset = 0xFFFFFFFF;
    uint32_t item = 0;
    token->is = OPERATOR;
    
    for (i = 0; i < NUM_OPERATORS; i ++)
    {
        found_ptr = find_in_file(in_buffer, operators[i], &length);
        if (found_ptr != NULL)
        {
            offset = (found_ptr - start_ptr);
            if (offset < prev_offset)
            {
                item = i;
                prev_offset = offset;
                prev_length = length;
            }
            else if (offset == prev_offset)
            {
                if (length > prev_length)
                {
                    item = i;
                    prev_length = length;
                }
            }
        }
		length = 0; 
    }
	if (offset == 0xFFFFFFFF)
    {
        return NOT_FOUND;
    }
    else
    {
        token->operator = (operator_t)item;
        populate_token(in_buffer, token, prev_offset, (prev_offset + prev_length));
        return SUCCESS;
    } 
}

/******************************************************************************/
/**********SEPARATORS**********************************************************/
/******************************************************************************/
/*
uint32_t find_separator(file_char_t * in_buffer, token_t * token)
{
    uint32_t i = 0;
    file_char_t * start_ptr = in_buffer;
    file_char_t * found_ptr;
    uint32_t length = 0;
    uint32_t offset = 0xFFFFFFFF;
    uint32_t prev_length = 0;
    uint32_t prev_offset = 0xFFFFFFFF;
    uint32_t item = 0;
    token->is = SEPARATOR;
    
    for (i = 0; i < NUM_SEPARATORS; i ++)
    {
        found_ptr = find_in_file(in_buffer, separators[i], &length);
        if (found_ptr != NULL)
        {
            offset = (found_ptr - start_ptr);
            if (offset < prev_offset)
            {
                item = i;
                prev_offset = offset;
                prev_length = length;
            }
            else if (offset == prev_offset)
            {
                if (length > prev_length)
                {
                    item = i;
                    prev_length = length;
                }
            }
        }
		length = 0;  
    }
	if (offset == 0xFFFFFFFF)
    {
        return NOT_FOUND;
    }
    else
    {
        token->separator = (separator_t)item;
        populate_token(in_buffer, token, prev_offset, (prev_offset + prev_length));
        return SUCCESS;
    }
}

/******************************************************************************/
/**********IDENTIFIERS*********************************************************/
/******************************************************************************/
/*
uint32_t find_identifier(file_char_t * in_buffer, token_t * token)
{
	uint32_t i = 0;
    uint32_t start_offset, end_offset;
    token->is = IDENTIFIER;
	while (in_buffer[i].value != '\0') {
		if (isalpha(in_buffer[i].value)) {
			start_offset = i;
			i ++;
			while (isalnum(in_buffer[i].value) || in_buffer[i].value == '_') {
				i ++;
			}
			end_offset = i;
			goto end;
		}
		i ++;
	}
	return NOT_FOUND;
	end:;
    populate_token(in_buffer, token, start_offset, end_offset);
	return SUCCESS;
}

/******************************************************************************/
/**********RECURSIVE TOKEN EXTRACTION******************************************/
/******************************************************************************/
/*
token_t * get_token_recursive(file_char_t * in_buffer, token_enum token_type) {
	uint32_t i;
	uint32_t offset;
	token_t * current_token = malloc(sizeof(token_t));
	current_token->last_token = NULL;
	token_t * head = current_token;
	token_t local_token;
    uint32_t status;
	switch (token_type)
	{
	case UNMATCHED:
		return NULL;
		break;
    case COMPILER_FLAG:
		status = find_compiler_flag(in_buffer, &local_token);
		break;
	case COMMENT:
		status = find_comment(in_buffer, &local_token);
		break;
	case STRING:
		status = find_string(in_buffer, &local_token);
		break;
    case NUMBER:
		status = find_number(in_buffer, &local_token);
		break;
    case KEYWORD:
		status = find_keyword(in_buffer, &local_token);
		break;
    case OPERATOR:
        status = find_operator(in_buffer, &local_token);
        break;
    case SEPARATOR:
        status = find_separator(in_buffer, &local_token);
        break;
	case IDENTIFIER:
		status = find_identifier(in_buffer, &local_token);
		break;
	}
	if (status != SUCCESS) {
		current_token->is = UNMATCHED;
		current_token->unmatched_buffer = in_buffer;
		return current_token;
	}
	offset = local_token.start_index - in_buffer->index;
	if (offset != 0) {
		current_token->is = UNMATCHED;
		current_token->unmatched_buffer = malloc((offset + 1) * sizeof(file_char_t));
		for (i = 0; i < offset; i ++) {
			current_token->unmatched_buffer[i] = in_buffer[i];
		}
		current_token->unmatched_buffer[offset + 1].value = '\0';
		current_token->unmatched_buffer[offset + 1].index = current_token->unmatched_buffer[offset].index + 1; //is this like really needed?
		current_token->next_token = malloc(sizeof(token_t));
		current_token->next_token->last_token = current_token; //!??
		current_token = current_token->next_token;
	}
	*current_token = local_token;
	//printf("%s\n", current_token->text);
	in_buffer += (offset + current_token->text_length);//(current_token->end_index - current_token->start_index));
	current_token->next_token = get_token_recursive(in_buffer, token_type);
	current_token->next_token->last_token = current_token;
	return head;
}

void tokenize_single_pass(token_t * current_token, token_enum token_type) {
	// loop until all tokens have been processed
	while (current_token != NULL) {
		// if the token type is unmatched create a sub list of all comment tokens in that token
		if (current_token->is == UNMATCHED) {
			token_t * sub_list = get_token_recursive(current_token->unmatched_buffer, token_type);
			if (sub_list == NULL) {
				printf("Error finding tokens of type: %d\n", token_type);
			}
			// park the rest of the current list
			token_t * rest_of_list = current_token->next_token;
            sub_list->last_token = current_token->last_token;
			// splice in the sub list
			*current_token = *sub_list;
			// travel to the end of the sub list
			while(current_token->next_token != NULL) {
				current_token = current_token->next_token;
			}
			// append the rest of the original list
			current_token->next_token = rest_of_list;
            if (current_token->next_token != NULL)
            {
                current_token->next_token->last_token = current_token;
            }	
		}
		// step along tokens list
		current_token = current_token->next_token;
	}
}

void clear_unmatched_tokens(token_t * current_token) {
	while (current_token != NULL)
	{
		if (current_token->next_token->is == UNMATCHED)
		{
			current_token->next_token = current_token->next_token->next_token;
            if (current_token->next_token != NULL)
            {
                current_token->next_token->last_token = current_token;
            }			
		}
		current_token = current_token->next_token;
	}
}

token_t * tokenize(source_file_t * source_file)
{
	token_t * token_list = malloc(sizeof(token_t));
	token_list->is = UNMATCHED;
	token_list->unmatched_buffer = source_file->characters;
	token_list->next_token = NULL;
	token_list->last_token = NULL;
    tokenize_single_pass(token_list, COMPILER_FLAG);
	tokenize_single_pass(token_list, COMMENT);
	tokenize_single_pass(token_list, STRING);
	tokenize_single_pass(token_list, KEYWORD);
	tokenize_single_pass(token_list, IDENTIFIER);
	tokenize_single_pass(token_list, NUMBER);
    tokenize_single_pass(token_list, OPERATOR);
    tokenize_single_pass(token_list, SEPARATOR);
	clear_unmatched_tokens(token_list);
	return token_list;
}
*/
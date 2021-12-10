#include <iostream>
#include <list>
#include <map>
#include "tokenizer.h"
#include "RP_parser.h"
#include "stack.h"

stack_class stack;

unsigned int RP_parser(std::list<struct token_list_node> * token_list)
{
	std::list<struct token_list_node>::iterator token_list_iter = token_list->begin();
	while (token_list_iter != token_list->end())
	{
		switch (token_list_iter->is)
		{
			case COMMAND_WORD:
			if (!stack.run_command(token_list_iter->cmd_string))
			{
				std::cerr << "Error: Invalid command word." << std::endl;
				return 0;
			}
			break;

			case NUMBER:
			stack.push(token_list_iter->number);
			break;

			default:
			break;
		}		
		token_list_iter ++;
	}
	token_list->clear();

	struct token_list_node result;
	result.is = NUMBER;
	if (!stack.pop(&result.number))
	{
		std::cerr << "Error: No result on the stack !!" << std::endl;
		return 0;
	} 

	token_list->push_back(result);
	return 1;
}
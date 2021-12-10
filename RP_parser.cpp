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
	stack.print_stack();
	token_list->clear();
	return 1;
}
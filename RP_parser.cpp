#include <iostream>
#include <list>
#include <map>
#include "tokenizer.h"
#include "RP_parser.h"

std::list<double> stack;

unsigned int RP_parser(std::list<struct token_list_node> * token_list)
{
	std::list<struct token_list_node>::iterator token_list_iter = token_list->begin();
	while (token_list_iter != token_list->end())
	{
		switch (token_list_iter->is)
		{
			case COMMAND_WORD:
			token_list_iter->cmd_word.function(&stack);
			break;

			case NUMBER:
			stack.push_back(token_list_iter->number);
			break;

			default:
			break;
		}		
		token_list_iter ++;
	}
	token_list->clear();

	struct token_list_node result;
	result.is = NUMBER;
	result.number = stack.back(); 

	token_list->push_back(result);
	return 1;
}
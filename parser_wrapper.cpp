#include <iostream>
#include <list>
#include "tokenizer.h"
#include "parser.h"
#include "RP_parser.h"

void parser_wrapper(std::list<struct token_list_section> token_lists)
{
	struct token_list_node node;
	std::list<struct token_list_node> combined_token_list;
	std::list<struct token_list_section>::iterator lists_iter = token_lists.begin();

	while (lists_iter != token_lists.end())
	{
		switch (lists_iter->type)
		{
			case EXPRESSION:
			node.is = NUMBER;
			node.number = parser(lists_iter->token_sub_list);
			combined_token_list.push_back(node);
			break;
			
			case COMMAND_SEQUENCE:
			combined_token_list.insert(combined_token_list.end(), lists_iter->token_sub_list.begin(), lists_iter->token_sub_list.end());
			break;
		
			default:
			break;
		}
		lists_iter ++;
	}

	if (!RP_parser(&combined_token_list))
	{
		std::cerr << "Error: Couldn't parse command expression." << std::endl;
	}
}
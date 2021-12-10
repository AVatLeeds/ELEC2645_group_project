#include <iostream>
#include <string>
#include <list>
#include "terminal_control.h"
#include "line_editor.h"
#include "tokenizer.h"
#include "RP_parser.h"
#include "parser.h"

std::string command_line;
bool run = true;
std::list<struct token_list_section> token_lists;


int main()
{
    try
    {
        enable_raw_mode();
		while (run)
		{
			command_line = get_line();


			tokenize(command_line, &token_lists);
			std::list<struct token_list_section>::iterator lists_iter = token_lists.begin();
			while (lists_iter != token_lists.end())
			{
				print_token_list(lists_iter->token_sub_list);
				lists_iter ++;
			}
			token_lists.clear();

		}
        disable_raw_mode();
    }
    catch(std::runtime_error * error)
    {
        std::cerr << error->what() << std::endl;
    }
    
    return 0;
}

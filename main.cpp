// To compile use:
// g++ -Wall terminal_control.cpp line_editor.cpp tokenizer.cpp RP_parser.cpp parser.cpp parser_wrapper.cpp stack.cpp main.cpp -o calculator.exec

#include <iostream>
#include <string>
#include <list>
#include "terminal_control.h"
#include "line_editor.h"
#include "tokenizer.h"
#include "RP_parser.h"
#include "parser.h"
#include "parser_wrapper.h"

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
			parser_wrapper(token_lists);
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

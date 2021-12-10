#include <iostream>
#include <string>
#include <list>
#include "terminal_control.h"
#include "line_editor.h"
#include "tokenizer.h"
#include "RP_parser.h"
#include "parser.h"

std::string command_line;
unsigned int i;
int bracket_count = 0;
bool expression_flag = false;
unsigned int index_opened;
unsigned int index_closed;
std::string command_expression;
bool run = true;
std::list<struct token_list_node> token_list_1;

int main()
{
    try
    {
        enable_raw_mode();
		while (run)
		{
			command_line = get_line();


			tokenize(command_line, &token_list_1);

		}
        disable_raw_mode();
    }
    catch(std::runtime_error * error)
    {
        std::cerr << error->what() << std::endl;
    }
    
    return 0;
}

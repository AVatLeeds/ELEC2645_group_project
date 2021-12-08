#include <iostream>
#include <string>
#include <list>
#include "terminal_control.h"
#include "line_editor.h"
#include "tokenizer.h"

std::string command_line;
unsigned int i;
int sqr_bracket_count = 0;
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
			for (i = 0; i < command_line.length(); i ++)
			{
				if (command_line[i] == '[')
				{
					sqr_bracket_count ++;
					if (sqr_bracket_count > 1)
					{
						std::cerr << "Error: invalid command expression. Command separators should not be nested." << std::endl;
						throw std::runtime_error("Square-bracket matching error."); 
					}
					else
					{
						index_opened = i;
					}
				}
				if (command_line[i] == ']')
				{
					sqr_bracket_count --;
					if (sqr_bracket_count < 0)
					{
						std::cerr << "Error: ']' without matching '['." << std::endl;
						throw std::runtime_error("Square-bracket matching error.");
					}
					else
					{
						index_closed = i;
						command_expression = command_line.substr((index_opened + 1), (index_closed - index_opened - 1));
						if (RP_tokenize(command_expression, &token_list_1))
						{

						}
						// do some shit
						std::cout << command_expression << std::endl;
						sqr_bracket_count = 0;
					}
				}
			}
		}
        disable_raw_mode();
    }
    catch(std::runtime_error * error)
    {
        std::cerr << error->what() << std::endl;
    }
    
    return 0;
}

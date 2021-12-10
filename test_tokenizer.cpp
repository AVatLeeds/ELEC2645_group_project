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

void print_token_list(std::list<struct token_list_node> list)
{
	std::list<struct token_list_node>::iterator list_iter = list.begin();
	while (list_iter != list.end())
	{
		switch (list_iter->is)
		{
			case COMMAND_WORD:
			std::cout << list_iter->cmd_string << " -> ";
			break;

			case NUMBER:
			std::cout << list_iter->number << " -> ";
			break;

			case OPERATOR:
			switch (list_iter->op)
			{
				case ADD:
				std::cout << '+';
				break;

				case SUB:
				std::cout << '-';
				break;

				case MUL:
				std::cout << '*';
				break;

				case DIV:
				std::cout << '/';
				break;

				case POW:
				std::cout << '^';
				break;
			
				default:
				break;
			}
			std::cout << " -> ";
			break;

			case SEPARATOR:
			switch (list_iter->sep)
			{
				case OPEN_EXPRESSION:
				std::cout << '(';
				break;

				case CLOSE_EXPRESSION:
				std::cout << ')';
				break;

				case OPEN_COMMAND:
				std::cout << '[';
				break;

				case CLOSE_COMMAND:
				std::cout << ']';
				break;
			
				default:
				break;
			}
			std::cout << " -> ";
			break;

			default:
			break;
		}		
		list_iter ++;
	}
	std::cout << std::endl;
}

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

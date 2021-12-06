//please

#include "tokenizer.h"
#include "line_editor.h"
#include "terminal_control.h"
#include <iostream>
#include <string>
#include <list>

int main()
{
  enable_raw_mode();
  std::list <struct Node> token_list;
  std::string command_line = get_line();
  std::cout << command_line << std::endl;
  tokenize(command_line, &token_list);

  std::cout << token_list.begin()->string << std::endl;
  std::list<struct Node>::iterator list_itr;

  for (list_itr = token_list.begin(); list_itr != token_list.end() ; list_itr ++)
  { 
    std::cout << list_itr->string << std::endl;
  }

  disable_raw_mode();
}

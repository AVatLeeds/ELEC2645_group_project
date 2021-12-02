#include "line_editor.h"
#include <iostream>
#include <string>
#include <list>
#include "tokenizer.h"


//std::string command_line = get_line();
//std::string command_line = "command line example";





void tokenize(std::string command_line, std::list<struct Node> * token_list)
{
  std::string place_holder;

  int j = 0;
  std::list<struct Node>::iterator list_itr;
  list_itr = (*token_list).begin();
  //std::cout << command_line[0] << std::endl;

  for (int i=0 ; i<command_line.length() ; i++)
  {
    //std::cout << command_line[i] << std::endl;
    if ( command_line[i] == ' ' )
    {
      //std::cout << place_holder << std::endl;
      
      struct Node new_node;
      new_node.string = place_holder;
      place_holder.clear();
      (*token_list).push_back(new_node);
      *list_itr = new_node;
    }
    else
    {
      place_holder.append({command_line[i]});
    }
    
  }
  struct Node new_node;
  new_node.string = place_holder;
  place_holder.clear();
  (*token_list).push_back(new_node);

  for (list_itr = (*token_list).begin(); list_itr != (*token_list).end() ; list_itr ++)
  { 
    std::cout << list_itr->string << std::endl;
    //peas
  }
}

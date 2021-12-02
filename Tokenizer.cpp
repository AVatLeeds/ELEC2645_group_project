//#include "line_editor.h"
#include <iostream>
#include <string>
#include <list>

//std::string command_line = get_line();
std::string command_line = "command line example";

enum item_types {COMMAND_WORD, NUMBER};

struct Node {
enum item_types item_type;
std::string command_word;
int number;
std::string string;
} ;

std::list<struct Node> token_list;
std::string place_holder;



int main()
{
  int j = 0;
  std::list<struct Node>::iterator list_itr;
  list_itr = token_list.begin();
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
      token_list.push_back(new_node);
      *list_itr = new_node;
      //std::cout << j << std::endl;
      
      /*
      while ( j < 10)
        struct Node new_node;
        new_node.string = place_holder;
        place_holder.clear();
        token_list.push_back(new_node);
        *list_itr = new_node;
        
      */
    }
    else
    {
      place_holder.append({command_line[i]});
    }
    
  }
  struct Node new_node;
    new_node.string = place_holder;
    place_holder.clear();
    token_list.push_back(new_node);
  //puts("here");
  list_itr = token_list.begin();
  for (list_itr = token_list.begin(); list_itr != token_list.end() ; list_itr ++)
  {
    //puts("here");
    if (list_itr->string == "brown")
    {
      std::cout << list_itr->string << std::endl;
    }
    //please
    std::cout << list_itr->string << std::endl;
    
    

  }
  //std::cout << place_holder << std::endl;
}

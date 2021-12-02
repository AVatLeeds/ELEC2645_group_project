#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <list>

enum item_types {COMMAND_WORD, NUMBER};

struct Node
{
  enum item_types item_type;
  std::string command_word;
  int number;
  std::string string;
} ;

void tokenize(std::string command_line, std::list <struct Node> * token_list);


#endif

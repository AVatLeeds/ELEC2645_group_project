#ifndef RP_PARSER_H
#define RP_PARSER_H

#include <list>
#include "tokenizer.h"

unsigned int RP_parser(std::list<struct token_list_node> * token_list);

#endif
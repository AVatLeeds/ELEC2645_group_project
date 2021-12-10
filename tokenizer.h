#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <list>
#include <map>

enum operators
{
	ADD,
	SUB,
	MUL,
	DIV,
	POW
	/*
	SQUARE_ROOT,
	EQUAL,
	UNEQUAL,
	LESS_THAN,
	GREATER_THAN,
	LESS_THAN_OR_EQUAL,
	GREATER_THAN_OR_EQUAL,
	*/
};
// things to add: arrays? assignment operator? bitwise logical operations? pointers?

enum separators
{
	OPEN_EXPRESSION,
	CLOSE_EXPRESSION,
	OPEN_COMMAND,
	CLOSE_COMMAND
};

enum token_type
{
		COMMAND_WORD,
		NUMBER,
		OPERATOR,
		SEPARATOR
};

struct token_list_node
{
	enum token_type is;
	std::string cmd_string;
	double number;
	enum operators op;
	enum separators sep;
};

enum token_list_type {EXPRESSION, COMMAND_SEQUENCE};

struct token_list_section
{
	enum token_list_type type;
	std::list<struct token_list_node> token_sub_list;
};

//unsigned int find_numbers(std::string command_line, std::list<struct token_list_node> * token_list, unsigned int start_idx);
//unsigned int find_command_words(std::string command_line, std::list<struct token_list_node> * token_list, unsigned int start_idx);

void print_token_list(std::list<struct token_list_node> list);
unsigned int tokenize_RP(std::string line, std::list<struct token_list_node> * token_list);
unsigned int tokenize_infix(std::string line, std::list<struct token_list_node> * token_list);
unsigned int tokenize(std::string line, std::list<struct token_list_section> * list_sections);

//unsigned int RP_tokenize(std::string command_line, std::list<struct token_list_node> * token_list);

#endif

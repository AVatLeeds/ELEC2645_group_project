#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <list>
#include <map>
#include "functions_homogenised.h"

enum operators
{
	ADD,
	SUB,
	MUL,
	DIV,
	POW,
	SQUARE_ROOT,
	EQUAL,
	UNEQUAL,
	LESS_THAN,
	GREATER_THAN,
	LESS_THAN_OR_EQUAL,
	GREATER_THAN_OR_EQUAL,
};
// things to add: arrays? assignment operator? bitwise logical operations? pointers?

//std::list<std::string> operators = {"+", "-", "*", "/", "^", "_/", "=", "/=", "<", ">", "<=", ">=", "(", ")", "{", "}"};

enum separators
{
	OPEN_EXPRESSION,
	CLOSE_EXPRESSION,
	OPEN_COMMAND,
	CLOSE_COMMAND
};

//std::list<std::string> separators = {"(", ")", "[", "]"};

struct command_info
{
	void (*function)(std::list<double> *);
	std::string description;
};

extern std::map<std::string, struct command_info> command_map;

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
	std::string literal_string; // for debug only
	unsigned int index;
	unsigned int length;
	struct command_info cmd_word;
	double number;
	enum operators op;
	enum separators sep;
};

//unsigned int find_numbers(std::string command_line, std::list<struct token_list_node> * token_list, unsigned int start_idx);
//unsigned int find_command_words(std::string command_line, std::list<struct token_list_node> * token_list, unsigned int start_idx);

unsigned int tokenize(std::string line, std::list<struct token_list_node> * token_list);

//unsigned int RP_tokenize(std::string command_line, std::list<struct token_list_node> * token_list);

#endif

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <list>
#include <map>
#include "functions_homogenised.h"

enum operators
{
	ADDITION,
	SUBTRACTION,
	MULTIPLICATION,
	DIVISION,
	SQUARE,
	SQUARE_ROOT,
	EQUAL,
	UNEQUAL,
	LESS_THAN,
	GREATER_THAN,
	LESS_THAN_OR_EQUAL,
	GREATER_THAN_OR_EQUAL,
	OPEN_EXPRESSION,
	CLOSE_EXPRESSION,
	OPEN_BLOCK,
	CLOSE_BLOCK,
	SURPRES
};
// things to add: arrays? assignment operator? bitwise logical operations? pointers?

std::list<std::string> operators = {"+", "-", "*", "/", "^", "_/", "=", "/=", "<", ">", "<=", ">=", "(", ")", "{", "}"};

enum separators
{
	OPEN_EXPRESSION,
	CLOSE_EXPRESSION,
	OPEN_COMMAND,
	CLOSE_COMMAND
};

std::list<std::string> separators = {"(", ")", "[", "]"};

struct command_info
{
	void (*function)(std::list<double> *);
	std::string description;
};

std::map<std::string, struct command_info> command_map
{
	// arithmetic
	{"add",			{&add,		"" }},
	{"sub",			{&subtract,	"" }},
	{"mul",			{&multiply,	"" }},
	{"div",			{&divide,	"" }},
	{"pow",			{&power,	"" }},	
	{"mod",			{&modulus,	"" }},
	{"abs",			{&absolute,	"" }},
	// logical
	{"and",			{&AND,		"" }},
	{"or",			{&OR,		"" }},
	{"not",			{&NOT,		"" }},
	{"nor",			{&NOR,		"" }},
	{"nand",		{&NAND,		"" }},
	{"xor",			{&XOR,		"" }},
	// stack manipulation
	{"dup", 		{&dup,		"" }},
	{"swap", 		{&swap,		"" }},
	{"push", 		{&push,		"" }},
	{"pop", 		{&pop,		"" }},
	{"roll", 		{&roll,		"" }},
	// system
	{"cmd_list", 	{&cmd_list,	"" }},
	{"help", 		{&help,		"" }},
	{"quit", 		{&quit,		"" }},	
	// other
	{"react",		{&react,	"" }},
	{"reluct",		{&reluct,	"" }},
	{"power_IV",	{&power_IV,	"" }},
	{"power_VR",	{&power_VR,	"" }}
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
	std::string literal_string; // for debug only
	unsigned int index;
	unsigned int length;
	struct command_info cmd_word;
	double number;
	enum operators op;
	enum separators sep;
};

unsigned int RP_tokenize(std::string command_line, std::list<struct token_list_node> * token_list);

#endif

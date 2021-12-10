#ifndef STACK_H
#define STACK_H

#include <list>
#include <map>



class stack_class {
	
	public:
	//constructors
	stack_class();
	// arithmetic
	void add();
	void subtract();
	void multiply();
	void divide();
	void power();
	void root();
	void modulus();
	void absolute();
	// logical
	void AND(); 
	void OR();
	void NOT();
	void NAND();
	void NOR();
	void XOR();
	// stack manipulation
	void clear();
	void dup();
	void swap();
	void stack_push();
	void stack_pop();
	void roll();
	// system
	void cmd_list();
	void help();
	void quit();
	// constants
	void pi();
	void plank();
	void reduced_plank();
	void boltzmann();
	void elec_charge();
	void elec_rest_mass(); 
	//other
	void quadratic_formula_1();
	void quadratic_formula_2();
	void electron_E();
	void eff_electron_E();

	private:
	unsigned int get_args(std::list<double *>);
	unsigned int push(double value);
	unsigned int pop(double * value);

	std::string status;
	std::list<double> stack;

	struct command_info
	{
		void (stack_class::*function)();
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
		{"pow",			{&root,		"" }},
		{"mod",			{&modulus,	"" }},
		{"abs",			{&absolute,	"" }},
		// logical
		{"and",			{&AND,		"" }},
		{"or",			{&OR,		"" }},
		{"not",			{&NOT,		"" }},
		{"nor",			{&NAND,		"" }},
		{"nand",		{&NOR,		"" }},
		{"xor",			{&XOR,		"" }},
		// stack manipulation
		{"dup", 		{&clear,		"" }},
		{"dup", 		{&dup,			"" }},
		{"swap", 		{&swap,			"" }},
		{"push", 		{&stack_push,	"" }},
		{"pop", 		{&stack_pop,	"" }},
		{"roll", 		{&roll,			"" }},
		// system
		{"cmd_list", 	{&cmd_list,	"" }},
		{"help", 		{&help,		"" }},
		{"quit", 		{&quit,		"" }},
		// constants
		{"_pi",			{&pi,				""}},
		{"_h",			{&plank,			""}},
		{"_h_bar",		{&reduced_plank,	""}},
		{"_kb",			{&boltzmann,		""}},
		{"_e",			{&elec_charge,		""}},
		{"_m0",			{&elec_rest_mass,	""}},
		// other
		{"quadratic_formula_positive",	{&quadratic_formula_1,	""}},
		{"quadratic_formula_negative",	{&quadratic_formula_2,	""}},
		{"electron_energy",				{&electron_E,			""}},
		{"effective_electron_energy",	{&eff_electron_E,		""}}
	};
};

#endif

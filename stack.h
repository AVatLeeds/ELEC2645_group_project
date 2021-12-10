#ifndef STACK_H
#define STACK_H

#include <list>
#include <map>

class stack_class {

	public:
	//constructors
	stack_class();

	unsigned int run_command(std::string);
	unsigned int push(double value);
	unsigned int pop(double * value);

	private:
	unsigned int get_args(std::list<double *>);

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

	std::string status;
	std::list<double> stack;

	struct command_info
	{
		void (stack_class:: * function)();
		std::string description;
	};

	std::map<std::string, struct command_info> command_map
	{
		// arithmetic
		{"add",			{&add,		"Adds two numbers." }},
		{"sub",			{&subtract,	"Subtracts two numbers." }},
		{"mul",			{&multiply,	"Multiplies two numbers." }},
		{"div",			{&divide,	"Divides two numbers." }},
		{"pow",			{&power,	"Raises one number to the power of another." }},
		{"root",		{&root,		"Calculates the nth root of the first number based on the second." }},
		{"mod",			{&modulus,	"Finds the modulus of the first number given the second." }},
		{"abs",			{&absolute,	"Finds the absolute value of a number." }},
		// logical
		{"and",			{&AND,		"Logical AND of two number." }},
		{"or",			{&OR,		"Logical OR of two number." }},
		{"not",			{&NOT,		"Logical NOT of a number." }},
		{"nand",		{&NAND,		"Logical NAND of two number." }},
		{"nor",			{&NOR,		"Logical NOR of two number." }},
		{"xor",			{&XOR,		"Logical XOR of two number." }},
		// stack manipulation
		{"dup", 		{&clear,		"Clears the stack." }},
		{"dup", 		{&dup,			"Duplicates the last number on the stack." }},
		{"swap", 		{&swap,			"Swaps the last two numbers on the stack." }},
		{"push", 		{&stack_push,	"Pushed a number on the stack." }},
		{"pop", 		{&stack_pop,	"Removes the number at the top of the stack." }},
		{"roll", 		{&roll,			"Rolls the numbers on the stack so that the first is now the last." }},
		// system
		{"cmd_list", 	{&cmd_list,	"Prints a helpful list of the commands and their descriptions :)." }},
		{"help", 		{&help,		"Displays a help screen with useful information." }},
		{"quit", 		{&quit,		"Quits the program." }},
		// constants
		{"_pi",			{&pi,				"Puts Pi on the top of the stack."}},
		{"_h",			{&plank,			"Puts the Plank constant on the top of the stack."}},
		{"_h_bar",		{&reduced_plank,	"Puts the reduced Plank constant on the top of the stack."}},
		{"_kb",			{&boltzmann,		"Puts the Boltzmann constant on the top of the stack."}},
		{"_e",			{&elec_charge,		"Puts the electron charge on the top of the stack."}},
		{"_m0",			{&elec_rest_mass,	"Puts the rest mass of the elctron on the top of the stack."}},
		// other
		{"quadratic_formula_positive",	{&quadratic_formula_1,	"Calculates quadratic formula using (-b + sqrt(b^2 - 4ac)) / 2a"}},
		{"quadratic_formula_negative",	{&quadratic_formula_2,	"Calculates quadratic formula using (-b - sqrt(b^2 - 4ac)) / 2a"}},
		{"electron_energy",				{&electron_E,			"Calculates electron energy given wave vector, k, and electron effective mass, m_e"}},
		{"effective_electron_energy",	{&eff_electron_E,		"Calculates electron energy given wave vector, k, and electron effective mass, m_e, taking into account bandgap energy Eg"}}
	};
};

#endif

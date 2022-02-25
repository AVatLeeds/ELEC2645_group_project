#ifndef STACK_H
#define STACK_H

#include <list>
#include <map>

class stack_class {

	public:
	//constructors
	stack_class();

	unsigned int	run_command(std::string);
	void 			print_stack();
	unsigned int	push(double value);
	unsigned int	pop(double * value);

	private:
	unsigned int get_args(std::list<double *>);

	// arithmetic
	void add();
	void subtract();
	void multiply();
	void divide();
	void power();
	void root();
	void sqrt();
	void logn();
	void log10();
	void log2();
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
	void permitivity_fs();
	void light_speed();
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
		{"add",			{&stack_class::add,		"Adds two numbers." }},
		{"sub",			{&stack_class::subtract,	"Subtracts two numbers." }},
		{"mul",			{&stack_class::multiply,	"Multiplies two numbers." }},
		{"div",			{&stack_class::divide,	"Divides two numbers." }},
		{"pow",			{&stack_class::power,	"Raises one number to the power of another." }},
		{"root",		{&stack_class::root,		"Calculates the nth root of the first number based on the second." }},
		{"sqrt",		{&stack_class::sqrt,		"Calculates the square root of the first number on the stack." }},
		{"logn",		{&stack_class::logn,		"Calculates the natural logarithm of the first number on the stack." }},
		{"log10",		{&stack_class::log10,		"Calculates the base 10 logarithm of the first number on the stack." }},
		{"log2",		{&stack_class::log2,		"Calculates the base 2 logarithm of the first number on the stack." }},
		{"mod",			{&stack_class::modulus,	"Finds the modulus of the first number given the second." }},
		{"abs",			{&stack_class::absolute,	"Finds the absolute value of a number." }},
		// logical
		{"and",			{&stack_class::AND,		"Logical AND of two number." }},
		{"or",			{&stack_class::OR,		"Logical OR of two number." }},
		{"not",			{&stack_class::NOT,		"Logical NOT of a number." }},
		{"nand",		{&stack_class::NAND,		"Logical NAND of two number." }},
		{"nor",			{&stack_class::NOR,		"Logical NOR of two number." }},
		{"xor",			{&stack_class::XOR,		"Logical XOR of two number." }},
		// stack manipulation
		{"clear", 		{&stack_class::clear,		"Clears the stack." }},
		{"dup", 		{&stack_class::dup,			"Duplicates the last number on the stack." }},
		{"swap", 		{&stack_class::swap,			"Swaps the last two numbers on the stack." }},
		{"push", 		{&stack_class::stack_push,	"Pushed a number on the stack." }},
		{"pop", 		{&stack_class::stack_pop,	"Removes the number at the top of the stack." }},
		{"roll", 		{&stack_class::roll,			"Rolls the numbers on the stack so that the first is now the last." }},
		// system
		{"cmd_list", 	{&stack_class::cmd_list,	"Prints a helpful list of the commands and their descriptions :)." }},
		{"help", 		{&stack_class::help,		"Displays a help screen with useful information." }},
		{"quit", 		{&stack_class::quit,		"Quits the program." }},
		// constants
		{"_pi",			{&stack_class::pi,				"Puts Pi on the top of the stack."}},
		{"_h",			{&stack_class::plank,			"Puts the Plank constant on the top of the stack."}},
		{"_h_bar",		{&stack_class::reduced_plank,	"Puts the reduced Plank constant on the top of the stack."}},
		{"_kb",			{&stack_class::boltzmann,		"Puts the Boltzmann constant on the top of the stack."}},
		{"_qe",			{&stack_class::elec_charge,		"Puts the electron charge on the top of the stack."}},
		{"_m0",			{&stack_class::elec_rest_mass,	"Puts the rest mass of the electron on the top of the stack."}},
		{"_e0",			{&stack_class::permitivity_fs,	"Puts the permitivity of free space on the top of the stack."}},
		{"_c",			{&stack_class::light_speed,		"Puts the speed of light on the top of the stack."}},
		// other
		{"quadratic_formula_positive",	{&stack_class::quadratic_formula_1,	"Calculates quadratic formula using (-b + sqrt(b^2 - 4ac)) / 2a"}},
		{"quadratic_formula_negative",	{&stack_class::quadratic_formula_2,	"Calculates quadratic formula using (-b - sqrt(b^2 - 4ac)) / 2a"}},
		{"electron_energy",				{&stack_class::electron_E,			"Calculates electron energy given wave vector, k, and electron effective mass, m_e"}},
		{"effective_electron_energy",	{&stack_class::eff_electron_E,		"Calculates electron energy given wave vector, k, and electron effective mass, m_e, taking into account bandgap energy Eg"}}
	};
};

#endif

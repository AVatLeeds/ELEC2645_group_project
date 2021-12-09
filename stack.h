#ifndef STACK_H
#define STACK_H

#include <list>

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
	void push();
	void pop();
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
};

#endif

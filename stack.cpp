#include <string>
#include <cmath>
#include "stack.h"

#define PLANK			6.626E-34
#define REDUCED_PLANK	PLANK / (2 * M_PI)
#define BOLTZMANN		1.381E-23
#define ELEC_CHARGE		1.602E-19
#define ELEC_REST_MASS	9.109E-31

stack_class::stack_class()
{

}

unsigned int stack_class::push(double value)
{
	stack.push_back(value);
}

unsigned int stack_class::pop(double * value)
{
	if (!stack.empty())
	{
		*value = stack.back();
		stack.pop_back();
		return 1;
	}
	else
	{
		return 0;
	}
}

unsigned int stack_class::get_args(std::list<double *> args)
{
	std::list<double *>::iterator args_iter = args.begin();
	while (!stack.empty())
	{
		**args_iter = stack.back();
		stack.pop_back();
		args_iter ++;
		if (args_iter == args.end())
		{
			return 1;
		}
	}
	return 0;
}


// arithmetic
void stack_class::add()
{
	double a, b;
	if (get_args({&a, &b}))
	{
		push(a + b);
		status = "OK";
	}
	status = "Error: Not enough operands on stack.";
}

void stack_class::subtract()
{
	double a, b;
	if (pop(&b))
	{
		if(pop(&a))
		{
			push(a - b);
			status = "OK";
		}
	}
	status = "Error: Not enough operands on stack.";
}

void stack_class::multiply()
{
	double a, b;
	if (pop(&b))
	{
		if(pop(&a))
		{
			push(a * b);
			status = "OK";
		}
	}
	status = "Error: Not enough operands on stack.";
}

void stack_class::divide()
{
	double a, b;
	if (pop(&b))
	{
		if (b == 0.0)
		{
			status = "Error: divide by zero.";
		}
		else if (pop(&a))
		{
			push(a / b);
			status = "OK";
		}
	}
	status = "Error: Not enough operands on stack.";
}

void stack_class::power()
{
	double a, b;
	if (pop(&b))
	{
		if(pop(&a))
		{
			push(pow(a, b));
			status = "OK";
		}
	}
	status = "Error: Not enough operands on stack.";
}

void stack_class::root()
{
	double a, b;
	if (pop(&b))
	{
		if(pop(&a))
		{
			push(pow(a, (1 / b)));
			status = "OK";
		}
	}
	status = "Error: Not enough operands on stack.";
}

void stack_class::modulus()
{
	double a, b;
	if (pop(&b))
	{
		if(pop(&a))
		{
			push((double)((int)a % (int)b));
			status = "OK";
		}
	}
	status = "Error: Not enough operands on stack.";
}

void stack_class::absolute()
{
	double a;
	if (pop(&a))
	{
		push(abs(a));
	}
	status = "Error: Not enough operands on stack.";
}

// logical
void stack_class::AND()
{
	double a, b;
	if (pop(&b))
	{
		if(pop(&a))
		{
			push((double)((int)a & (int)b));
			status = "OK";
		}
	}
	status = "Error: Not enough operands on stack.";
}

void stack_class::OR()
{
	double a, b;
	if (pop(&b))
	{
		if(pop(&a))
		{
			push((double)((int)a | (int)b));
			status = "OK";
		}
	}
	status = "Error: Not enough operands on stack.";
}

void stack_class::NOT()
{
	double a;
	if (pop(&a))
	{
		push((double)(~(int)a));
	}
	status = "Error: Not enough operands on stack.";
}

void stack_class::NAND()
{
	double a, b;
	if (pop(&b))
	{
		if(pop(&a))
		{
			push((double)(~((int)a & (int)b)));
			status = "OK";
		}
	}
	status = "Error: Not enough operands on stack.";
}

void stack_class::NOR()
{
	double a, b;
	if (pop(&b))
	{
		if(pop(&a))
		{
			push((double)(~((int)a & (int)b)));
			status = "OK";
		}
	}
	status = "Error: Not enough operands on stack.";
}

void stack_class::XOR()
{
	double a, b;
	if (pop(&b))
	{
		if(pop(&a))
		{
			push((double)((int)a ^ (int)b));
			status = "OK";
		}
	}
	status = "Error: Not enough operands on stack.";
}

// stack manipulation
void stack_class::clear()
{
	stack.clear();
}

void stack_class::dup()
{
	double a;
	if(pop(&a))
	{
		push(a);
		push(a);
		status = "OK";
	}
	status = "Error: Not enough operands on stack.";
}

void stack_class::swap()
{
	double a, b;
	if(pop(&b))
	{
		if (pop(&a))
		{
			push(b);
			push(a);
			status = "OK";
		}
	}
	status = "Error: Not enough operands on stack.";
}

void stack_class::push() // has no overall effect
{
	double a;
	if(pop(&a))
	{
		push(a);
		status = "OK";
	}
	status = "Error: Not enough operands on stack.";
}

void stack_class::pop() // has no overall effect
{
	double a;
	if(pop(&a))
	{
		status = "OK";
	}
	status = "Error: Not enough operands on stack.";
}

void stack_class::roll() // has no overall effect
{
	double a;
	if(pop(&a))
	{
		stack.push_front(a);
		status = "OK";
	}
	status = "Error: Not enough operands on stack.";
}

//constants
void stack_class::pi()
{
	stack.push_back(M_PI);
}

void stack_class::plank()
{
	stack.push_back(PLANK);
}

void stack_class::reduced_plank()
{
	stack.push_back(REDUCED_PLANK);
}

void stack_class::boltzmann()
{
	stack.push_back(BOLTZMANN);
}

void stack_class::elec_charge()
{
	stack.push_back(ELEC_CHARGE);
}

void stack_class::elec_rest_mass()
{
	stack.push_back(ELEC_REST_MASS);
}

// other
void stack_class::quadratic_formula_1()
{
	double a, b, c;
	if (get_args({&a, &b, &c}))
	{
		double discriminant = pow(b, 2.0) - (4.0 * a * c);
		if (discriminant < 0.0)
		{
			status = "Error: Discriminant less than zero. Complex root (we don't do these yet).";
		}
		else
		{
			stack.push_back((-b + sqrt(discriminant)) / (2.0 * a));
		}
	}
	status = "Error: Not enough operands on stack.";
}

void stack_class::quadratic_formula_2()
{
	double a, b, c;
	if (get_args({&a, &b, &c}))
	{
		double discriminant = pow(b, 2.0) - (4.0 * a * c);
		if (discriminant < 0.0)
		{
			status = "Error: Discriminant less than zero. Complex root (we don't do these yet).";
		}
		else
		{
			stack.push_back((-b - sqrt(discriminant)) / (2.0 * a));
		}
	}
	status = "Error: Not enough operands on stack.";
}

void stack_class::electron_E()
{
	double k, m_e;
	if (get_args({&k, &m_e}))
	{
		stack.push_back((pow(REDUCED_PLANK, 2) * pow(k, 2)) / (2.0 * m_e));
	}
	status = "Error: Not enough operands on stack.";
}

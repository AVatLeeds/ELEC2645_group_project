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

void stack_class::stack_push() // has no overall effect
{
	double a;
	if(pop(&a))
	{
		push(a);
		status = "OK";
	}
	status = "Error: Not enough operands on stack.";
}

void stack_class::stack_pop() // has no overall effect
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

unsigned int quadratic_form_1(double a, double b, double c, double * result)
{
	double discriminant = pow(b, 2.0) - (4.0 * a * c);
	if (discriminant < 0.0)
	{
		return 0;
	}
	else
	{
		*result = (-b + sqrt(discriminant)) / (2.0 * a);
		return 1;
	}
}

void stack_class::quadratic_formula_1()
{
	double a, b, c;
	if (get_args({&a, &b, &c}))
	{
		double result;
		if (quadratic_form_1(a, b, c, &result))
		{
			stack.push_back(result);
			status = "OK";
			return;
		}
		status = "Error: Discriminant less than zero. Complex root (we don't do these yet).";
	}
	status = "Error: Not enough operands on stack.";
}

unsigned int quadratic_form_2(double a, double b, double c, double * result)
{
	double discriminant = pow(b, 2.0) - (4.0 * a * c);
	if (discriminant < 0.0)
	{
		return 0;
	}
	else
	{
		*result = (-b - sqrt(discriminant)) / (2.0 * a);
		return 1;
	}
}

void stack_class::quadratic_formula_2()
{
	double a, b, c;
	if (get_args({&a, &b, &c}))
	{
		double result;
		if (quadratic_form_2(a, b, c, &result))
		{
			stack.push_back(result);
			status = "OK";
			return;
		}
		status = "Error: Discriminant less than zero. Complex root (we don't do these yet).";
	}
	status = "Error: Not enough operands on stack.";
}

double electron_Energy(double k, double m_e)
{
	return (pow(REDUCED_PLANK, 2) * pow(k, 2)) / (2.0 * m_e);
}

void stack_class::electron_E()
{
	double k, m_e;
	if (get_args({&k, &m_e}))
	{
		stack.push_back(electron_Energy(k, m_e));
		status = "OK";
		return;
	}
	status = "Error: Not enough operands on stack.";
}

void stack_class::eff_electron_E()
{
	double k, m_e, Eg;
	if (get_args({&k, &m_e, &Eg}))
	{
		double result_1, result_2;
		if (quadratic_form_1((1 / Eg), 1, -(electron_Energy(k, m_e)), &result_1))
		{
			if (quadratic_form_2((1 / Eg), 1, -(electron_Energy(k, m_e)), &result_2))
			{
				if (result_1 >= 0.0)
				{
					stack.push_back(result_1);
					status = "OK";
					return;
				}
				else if (result_2 >= 0.0)
				{
					stack.push_back(result_2);
					status = "OK";
					return;
				}
				else
				{
					status = "Error: Both results were negative.";
					return;
				}
			}
		}
		status = "Error: Discriminant less than zero. Complex root (we don't do these yet).";
		return;
	}
	status = "Error: Not enough operands on stack.";
}
		

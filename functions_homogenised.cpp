#include <iostream>
#include <list>
#include <cmath>
#include <complex>
#include "functions.h"

#define PLANK 6.626e-34

#define BINARY_OP(X) double a = stack->back(); \
    stack->pop_back(); \
    double b = stack->back(); \ 
    stack->pop_back(); \
    stack->push_back(a X b);

// Implement bounds checking? how?

double unary_op()
{

}

double binary_op()
{
    
}

double pop(std::list<double> * stack)
{

}

void add (std::list<double> * stack) //addition function
{
    BINARY_OP(+)
}

void subtract (std::list<double> * stack) //subtraction function
{
    BINARY_OP(-)
}

void multiply (std::list<double> * stack) //multiplication function
{
    BINARY_OP(*)
}

void divide (std::list<double> * stack) //division function
{
    double a = stack->back();
    stack->pop_back();
    double b = stack->back();
    stack->pop_back();
    if (b == 0.0)
    {
        // throw should be used here. Figure out how.
        std::cerr << "Error: Divide by zero." << std::endl;
        return;
    }
    else
    {
        stack->push_back(a / b);
    }
}

void power (std::list<double> * stack) //power function
{
    double a = stack->back();
    stack->pop_back();
    double b = stack->back();
    stack->pop_back();
    stack->push_back(pow(a, b));
}

/*double root (double a , double b) //root function , unused it is easier to do power at the moment, can implement later?
{
    return pow(a,1/b);
} */

void modulus (std::list<double> * stack) //modulus function 
{
    double a = stack->back();
    stack->pop_back();
    double b = stack->back();
    stack->pop_back();
    stack->push_back((double)((int)a % (int)b));
}

void absolute (std::list<double> * stack) //absolute function
{
    double a = stack->back();
    stack->pop_back();
    stack->push_back(abs(a));;
}

//for the bool function we use unsigned integers for simplicity

double AND (double a , double b) //boolean AND function
{
    return (unsigned int)a & (unsigned int)b;
}

double OR (double a , double b) //boolean OR function
{
    return (unsigned int)a | (unsigned int)b;
}

double NOT (double a) //boolean NOT function
{
    return !(unsigned int)a; 
}

double NOR (double a , double b) //boolean NOR function
{
    return !((unsigned int)a | (unsigned int)b);
}

double XOR (double a , double b) //boolean XOR function
{
    return ((unsigned int)a ^ (unsigned int)b);
}

double NAND (double a , double b) //boolean NAND function
{
    return !((unsigned int)a & (unsigned int)b);
}

double react (double f , double c) //complex reactance function
{
    std::complex<double> j(0.0, 1.0);
    return imag(-j * (1/(2 * M_PI * f * c))); //returns the imaginary value (as oppose to the resistance)
}

double reluct (double f, double l) //complex reluctance function
{
    std::complex<double> j(0.0, 1.0);
    return imag(j * 2.0 * M_PI * f * l); //returns the imaginary value (as oppose to the resistance)
}

double power_IV (double i , double v) //power function
{
    return (i*v);
}

double power_VR (double v , double r)
{
    return (pow(v , 2) / r);
}

double power_RI (double r , double i)
{
    return (r * (pow(i , 2)));
}

double curr_PR (double p, double r) //current functions
{
    return (sqrt(p / r));
}

double curr_PV (double p, double v)
{
    return (p / v);
}

double curr_VR (double v, double r)
{
    return (v / r);
}

double resis_VP (double v, double p) //resistance functions
{
    return (pow(v , 2)/ p);
}

double resis_PI (double p, double i)
{
    return (p / (pow(i , 2)));
}

double resis_VI (double v, double i)
{
    return (v / i);
}

double volt_IR (double i , double r) //voltage functions
{
    return (i*r);
}

double volt_PI (double p , double i)
{
    return (p / i);
}

double volt_PR (double p , double r)
{
    return (sqrt(p * r));
}

double capacit_QV (double q, double v) //capacitance function
{
    return q / v;
}

double capacit_series (double c1, double c2) //circuit theory functions
{
    return (1/c1) + (1/c2);
}

double capacit_parallel (double c1, double c2)
{
    return c1 + c2;
}

double resist_series (double r1, double r2)
{
    return r1 + r2;
}

double resist_parallel (double r1, double r2)
{
    return (1/r1) + (1/r2);
}

double freq_T (double t) //frequency and time functions
{
    return 1/t;
}

double time_F (double f)
{
    return 1/f;
}

double freq_VH (double v, double h) //wavespeed divided by wavelength
{
    return (v / h);
}

double  freq_W (double w) //angular frequency
{
    return ((w) / (2 * M_PI));
}

double OscillFreq (double l, double c) //frequency of oscillation using capactiance and inductance
{
    return (1 / (2 * M_PI * (sqrt(l * c))));
}

/*
double HeadorTails (double ) //heads or tails function WIP
{
    random
}
*/


double quadratForm1 (double a , double b , double c) //quadratic formula function, first solution
{
    return ((-b + sqrt(pow(b , 2) - (4 * a * c)))/ (2 * a));
}

double quadratForm2 (double a , double b , double c) //quadratic formula function, second solution
{
    return ((-b - sqrt(pow(b , 2) - (4 * a * c)))/ (2 * a));
}

double electronE (double k, double me) //used to calculate the electron energy
{
  return (pow((PLANK / (2 * M_PI) ), 2) * pow(k, 2)) / (2.0 * me);

  
}

double effElectronE (double k , double me , double Eg) //combines the quadratic formula and the fomula used to calculate the assumed energy to calculate actual energy with the bandgap
{
     double resultsa = quadratForm1((1.0/Eg), 1.0, -(electronE(k , me)));
    double resultsb = quadratForm2((1.0/Eg), 1.0, -(electronE(k , me)));

    if (resultsa >= 0)
    {
      return resultsa;
    }
    if (resultsb >= 0)
    {
      return resultsb;
    }
}
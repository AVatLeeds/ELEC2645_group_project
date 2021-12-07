#include <iostream>
#include <cmath>
#include <complex>

#define PLANK 6.626e-34

double sum (double a , double b) //addition function
{
    return a + b;
}

double sub (double a , double b) //subtraction function
{
    return a - b;
}

double mult (double a , double b) //multiplication function
{
    return a * b;
}

double div (double a , double b) //division function
{
    return a / b;
}

double pow (double a , double b) //power function
{
    return pow(a,b);
}

/*double root (double a , double b) //root function , unused it is easier to do power at the moment, can implement later?
{
    return pow(a,1/b);
} */

double mod (double a , double b) //modulus function 
{
    return a % b;
}

double abs (double a) //absolute function
{
    return abs(a)
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
    return ((unsigned int)a ^ (unsigned int))b);
}

double NAND (double a , double b) //boolean NAND function
{
    return !((unsigned int)a & (unsigned int)b);
}

double quadratForm1 (double a , double b , double c) //quadratic formula function, first solution
{
    return ((-b + sqrt(pow(b , 2) - 4 * a * c))/ 2 * a);
}

double quadratForm2 (double a , double b , double c) //quadratic formula function, second solution
{
    return ((-b - sqrt(pow(b , 2) - 4 * a * c))/ 2 * a);
}


double react (double f , double c) //complex reactance function
{
    std::complex<double> j(0.0, 1.0);
    return imag(-j * (1/(2 * M_PI * f * c))); //returns the imaginary value (as oppose to the resistance)
}

double reluct (double f, double l) //complex reluctance function
{
    std::complex<double> j(0.0, 1.0);
    return imag(j * 2 * M_PI * f * l); //returns the imaginary value (as oppose to the resistance)
}

double electronE (double k, double me)
{
    return (pow((PLANK / (2 * M_PI) ), 2) * pow(k, 2)) / (2.0 * me);
}

double effElectronE (double k , double me , double Eg)
{
    double sol1 = quadratForm1(1/Eg, 1, -electronE(k , me));
    double sol2 = quadratForm2(1/Eg, 1, -electronE(k , me));

    if (sol1 < 0)
    {   
        return sol1;
    }
    if (sol2 < 0);
    {
        return sol2;
    }
}

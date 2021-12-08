#include <iostream>
#include <cmath>
#include <complex>
#include "functions.h"

#define PLANK 6.626e-34

double sum(double a, double b) //addition function
{
    return a + b;
}

double sub(double a, double b) //subtraction function
{
    return a - b;
}

double mult(double a, double b) //multiplication function
{
    return a * b;
}

double div(double a, double b) //division function
{
    return a / b;
}

double pow(double a, double b) //power function
{
    return pow(a, b);
}

/*double root (double a , double b) //root function , unused it is easier to do power at the moment, can implement later?
{
    return pow(a,1/b);
} */

double mod(double a, double b) //modulus function 
{
    return (int)a % (int)b; //cast a and b
}

double abs(double a) //absolute function
{
    return abs(a);
}

//for the bool function we use unsigned integers for simplicity

double AND(double a, double b) //boolean AND function
{
    return (unsigned int)a & (unsigned int)b;
}

double OR(double a, double b) //boolean OR function
{
    return (unsigned int)a | (unsigned int)b;
}

double NOT(double a) //boolean NOT function
{
    return !(unsigned int)a;
}

double NOR(double a, double b) //boolean NOR function
{
    return !((unsigned int)a | (unsigned int)b);
}

double XOR(double a, double b) //boolean XOR function
{
    return ((unsigned int)a ^ (unsigned int)b);
}

double NAND(double a, double b) //boolean NAND function
{
    return !((unsigned int)a & (unsigned int)b);
}

double react(double f, double c) //complex reactance function
{
    std::complex<double> j(0.0, 1.0);
    return imag(-j * (1 / (2 * M_PI * f * c))); //returns the imaginary value (as oppose to the resistance)
}

double reluct(double f, double l) //complex reluctance function
{
    std::complex<double> j(0.0, 1.0);
    return imag(j * 2.0 * M_PI * f * l); //returns the imaginary value (as oppose to the resistance)
}

double power_IV(double i, double v) //power function
{
    return (i * v);
}

double power_VR(double v, double r)
{
    return (pow(v, 2) / r);
}

double power_RI(double r, double i)
{
    return (r * (pow(i, 2)));
}

double curr_PR(double p, double r) //current functions
{
    return (sqrt(p / r));
}

double curr_PV(double p, double v)
{
    return (p / v);
}

double curr_VR(double v, double r)
{
    return (v / r);
}

double resis_VP(double v, double p) //resistance functions
{
    return (pow(v, 2) / p);
}

double resis_PI(double p, double i)
{
    return (p / (pow(i, 2)));
}

double resis_VI(double v, double i)
{
    return (v / i);
}

double volt_IR(double i, double r) //voltage functions
{
    return (i * r);
}

double volt_PI(double p, double i)
{
    return (p / i);
}

double volt_PR(double p, double r)
{
    return (sqrt(p * r));
}

double capacit_QV(double q, double v) //capacitance function
{
    return q / v;
}

double capacit_series(double c1, double c2) //circuit theory functions
{
    return 1/((1 / c1) + (1 / c2));
}

double capacit_parallel(double c1, double c2)
{
    return c1 + c2;
}

double resist_series(double r1, double r2)
{
    return r1 + r2;
}

double resist_parallel(double r1, double r2)
{
    return 1/((1 / r1) + (1 / r2));
}

double freq_T(double t) //frequency and time functions
{
    return 1 / t;
}

double time_F(double f)
{
    return 1 / f;
}

double freq_VH(double v, double h) //wavespeed divided by wavelength
{
    return (v / h);
}

double  freq_W(double w) //angular frequency
{
    return ((w) / (2 * M_PI));
}

double OscillFreq(double l, double c) //frequency of oscillation using capactiance and inductance
{
    return (1 / (2 * M_PI * (sqrt(l * c))));
}

/*
double HeadorTails (double ) //heads or tails function WIP
{
    random
}
*/

double circle_Area(double r) //area of circle function
{
  return (M_PI * (pow(r , 2)));
}

double circle_Circum(double r) //circumference of circle function
{
  return (2 * M_PI * r);
}

double triangle_OH(double o, double h) //angle between opposite and hypotenuse
{
  return (asin(o / h) * (180 / M_PI)); 
}

double triangle_AH(double a, double h) //angle between adjacent and hypotenuse
{
  return (acos(a / h) * (180 / M_PI)); 
}

double triangle_OA(double o, double a) //angle between opposite and adjacent
{
  return (atan(o / a) * (180 / M_PI)); 
}

double triangle_SH(double s_angle, double h) //opposite length (with hypotenuse)
{
  return (sin(s_angle) * h);
}

double triangle_CH(double c_angle, double h) //adjacent length
{
  return (cos(c_angle) * h);
}

double triangle_TH(double t_angle, double a) //opposite length (with adjacent)
{
  return (sin(t_angle) * a);
}

double triangle_Area(double b, double h)
{
  return (0.5 * b * h);
}

double sin_calc(double d)
{
  return sin(d);
}

double cos_calc(double d)
{
  return cos(d);
}

double tan_calc(double d)
{
  return sin(d);
}

double log_calc(double a)
{
  return log(a);
}

double base2_log_calc(double a)
{
  return (log_calc(a)/log_calc(2));
}

double quadratForm1(double a, double b, double c) //quadratic formula function, first solution
{
    /*if (pow(b, 2) <= (4 * a * c)) //Fails if the solution in the square root is negative because we don't want to deal with imaginary numbers here
    {
        std::cout << "Invalid Inputs";
    }
    */
    return ((-b + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a));
}

double quadratForm2(double a, double b, double c) //quadratic formula function, second solution
{
    /*if (pow(b, 2) <= (4 * a * c)) //Fails if the solution in the square root is negative because we don't want to deal with imaginary numbers here
    {
        std::cout << "Invalid Inputs";
    }
    */
    return ((-b - sqrt(pow(b, 2) - (4 * a * c))) / (2 * a));
}

double electronE(double k, double me) //used to calculate the electron energy
{
    return (pow((PLANK / (2 * M_PI)), 2) * pow(k, 2)) / (2.0 * me);


}

double effElectronE(double k, double me, double Eg) //combines the quadratic formula and the fomula used to calculate the assumed energy to calculate effective energy with the bandgap
{
    double resultsa = quadratForm1((1.0 / Eg), 1.0, -(electronE(k, me)));
    double resultsb = quadratForm2((1.0 / Eg), 1.0, -(electronE(k, me)));

    if (resultsa >= 0) //This will have two results but only the positive result is correct
    {
        return resultsa;
    }
    if (resultsb >= 0)
    {
        return resultsb;
    }
}

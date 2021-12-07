#ifndef FUNCTIONS_H
#define FUNCTIONS_H

double sum (double a , double b); //addition function

double sub (double a , double b); //subtraction function

double mult (double a , double b); //multiplication function

double div (double a , double b); //division function

double pow (double a , double b); //power function

/*double root (double a , double b) //root function , unused it is easier to do power at the moment, can implement later?
{
    return pow(a,1/b);
} */

double mod (double a , double b); //modulus function 

double abs (double a); //absolute function

//for the bool function we use unsigned integers for simplicity

double AND (double a , double b); //boolean AND function

double OR (double a , double b); //boolean OR function

double NOT (double a); //boolean NOT function

double NOR (double a , double b); //boolean NOR function

double XOR (double a , double b); //boolean XOR function

double NAND (double a , double b); //boolean NAND function

double react (double f , double c); //complex reactance function

double reluct (double f, double l); //complex reluctance function

double power_IV (double i , double v); //power function

double power_VR (double v , double r);

double power_RI (double r , double i);

double curr_PR (double p, double r); //current functions

double curr_PV (double p, double v);

double curr_VR (double v, double r);

double resis_VP (double v, double p); //resistance functions

double resis_PI (double p, double i);

double resis_VI (double v, double i);

double volt_IR (double i , double r); //voltage functions

double volt_PI (double p , double i);

double volt_PR (double p , double r);

double capacit_QV (double q, double v); //capacitance function

double capacit_series (double c1, double c2); //circuit theory functions

double capacit_parallel (double c1, double c2);

double resist_series (double r1, double r2);

double resist_parallel (double r1, double r2);

double freq_T (double t); //frequency and time functions

double time_F (double f);

double freq_VH (double v, double h); //wavespeed divided by wavelength

double  freq_W (double w); //angular frequency

double OscillFreq (double l, double c); //frequency of oscillation using capactiance and inductance

/*
double HeadorTails (double ) //heads or tails function WIP
*/

double quadratForm1 (double a , double b , double c); //quadratic formula function, first solution

double quadratForm2 (double a , double b , double c); //quadratic formula function, second solution

double electronE (double k, double me); //used to calculate the electron energy

double effElectronE (double k , double me , double Eg); //combines the quadratic formula and the fomula used to calculate the assumed energy to calculate actual energy with the bandgap

#endif

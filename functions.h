#ifndef FUNCTIONS_H
#define FUNCTIONS_H

double sum(double a, double b); //addition function

double sub(double a, double b); //subtraction function

double mult(double a, double b); //multiplication function

double div(double a, double b); //division function

double power(double a, double b); //power function

/*double root (double a , double b) //root function , unused it is easier to do power at the moment, can implement later?
*/

double mod(double a, double b); //modulus function 

double abs(double a); //absolute function

//for the bool function we use unsigned integers for simplicity

double AND(double a, double b); //boolean AND function

double OR(double a, double b); //boolean OR function

double NOT(double a); //boolean NOT function

double NOR(double a, double b); //boolean NOR function

double XOR(double a, double b); //boolean XOR function

double NAND(double a, double b); //boolean NAND function

double react(double f, double c); //complex reactance function

double reluct(double f, double l); //complex reluctance function

double power_IV(double i, double v); //power function

double power_VR(double v, double r);

double power_RI(double r, double i);

double curr_PR(double p, double r); //current functions

double curr_PV(double p, double v);

double curr_VR(double v, double r);

double resis_VP(double v, double p); //resistance functions

double resis_PI(double p, double i);

double resis_VI(double v, double i);

double volt_IR(double i, double r); //voltage functions

double volt_PI(double p, double i);

double volt_PR(double p, double r);

double capacit_QV(double q, double v); //capacitance function

double capacit_series(double c1, double c2); //circuit theory functions

double capacit_parallel(double c1, double c2);

double resist_series(double r1, double r2);

double resist_parallel(double r1, double r2);

double freq_T(double t); //frequency and time functions

double time_F(double f);

double freq_VH(double v, double h); //wavespeed divided by wavelength

double  freq_W(double w); //angular frequency

double OscillFreq(double l, double c); //frequency of oscillation using capactiance and inductance

/*
double HeadorTails (double ) //heads or tails function WIP
*/

double circle_Area(double r); //area of circle function

double circle_Circum(double r); //circumference of circle function

double triangle_OH(double o, double h); //angle between opposite and hypotenuse

double triangle_AH(double a, double h); //angle between adjacent and hypotenuse

double triangle_OA(double o, double a); //angle between opposite and adjacent

double triangle_SH(double s_angle, double h); //opposite length (with hypotenuse)

double triangle_CH(double c_angle, double h); //adjacent length

double triangle_TH(double t_angle, double a); //opposite length (with adjacent)

double triangle_Area(double b, double h);

double sin_calc(double d);

double cos_calc(double d);

double tan_calc(double d);

double log_calc(double a);

double base2_log_calc(double a);

double quadratForm1(double a, double b, double c); //quadratic formula function, first solution

double quadratForm2(double a, double b, double c); //quadratic formula function, second solution

double electronE(double k, double me); //used to calculate the electron energy

double effElectronE(double k, double me, double Eg); //combines the quadratic formula and the fomula used to calculate the assumed energy to calculate actual energy with the bandgap

#endif

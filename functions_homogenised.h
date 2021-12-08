#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <list>

// arithmetic
void add		(std::list<double> * stack); //addition function
void subtract	(std::list<double> * stack); //subtraction function
void multiply	(std::list<double> * stack); //multiplication function
void divide		(std::list<double> * stack); //division function
void power		(std::list<double> * stack); //power function
void root		(std::list<double> * stack); // root function
void modulus	(std::list<double> * stack); //modulus function 
void absolute	(std::list<double> * stack); //absolute function
// logical
void AND		(std::list<double> * stack); 
void OR			(std::list<double> * stack);
void NOT		(std::list<double> * stack);
void NOR		(std::list<double> * stack);
void NAND		(std::list<double> * stack);
void XOR		(std::list<double> * stack);
// stack manipulation
void dup		(std::list<double> * stack);
void swap		(std::list<double> * stack);
void push		(std::list<double> * stack);
void pop		(std::list<double> * stack);
void roll		(std::list<double> * stack);
// system
void cmd_list	(std::list<double> * stack);
void help		(std::list<double> * stack);
void quit		(std::list<double> * stack);
// other
void react		(std::list<double> * stack);
void reluct		(std::list<double> * stack);
void power_IV	(std::list<double> * stack);
void power_VR	(std::list<double> * stack);
void power_RI	(std::list<double> * stack);
void curr_PR	(std::list<double> * stack);
void curr_pv	(std::list<double> * stack);
void resis_VP	(std::list<double> * stack);
void resis_pi	(std::list<double> * stack);
void resis_vi	(std::list<double> * stack);
void volt_IR	(std::list<double> * stack);
void volt_PI	(std::list<double> * stack);
void volt_PR	(std::list<double> * stack);
void capacit_QV	(std::list<double> * stack);
void capacit_series		(std::list<double> * stack);
void capacit_parallel	(std::list<double> * stack);
void resist_series		(std::list<double> * stack);
void resisr_parallel	(std::list<double> * stack);
void freq_t		(std::list<double> * stack);
void time_F		(std::list<double> * stack);
void freq_VH	(std::list<double> * stack);
void freq_W		(std::list<double> * stack);
void OscillFreq	(std::list<double> * stack);

#endif

#include <iostream>
#include <string>
#include "functions.h"

double a;
double b;
double c;
double ans;

//Within this file we manually change the input numbers and then we calculate the answer with a calculator and then run the file and see if the answers are the same

typedef enum test_names
{
    SUM,
    POWER,
    REACTANCE,
    RELUCTANCE,
    CAPACITANCE_SERIES,
    RESIST_PARALLEL,
    FREQUENCY_ANGULAR,
    OSCILLATING_FREQUENCY,
    QUADRATIC_FORMULA1,
    ELECTRON_ENERGY,
    EFFECTIVE_ELECTRON_ENERGY,
    BASE_TWO_LOG,
    CIRCLE_AREA

} test_t;

test_t test = EFFECTIVE_ELECTRON_ENERGY; //Change the test case here

int main()
{
    switch (test)
    {
    case SUM:
        a = 2;
        b = 5;
        ans = sum(a, b);
        std::cout << ans;
        break;

    case POWER:
        a = 2;
        b = 5;
        ans = power(a, b);
        std::cout << ans;
        break;

    case REACTANCE:
        a = 50; //frequency (Hz)
        b = 0.0001; //capacitance (F)
        ans = react(a, b);
        std::cout << ans;
        break;

    case RELUCTANCE:
        a = 50; //frequency (Hz)
        b = 0.0001; //inductance (H)
        ans = reluct(a, b);
        std::cout << ans;
        break;

    case CAPACITANCE_SERIES:
        a = 0.00005; //capacitance (F)
        b = 0.0001; //capacitance (F)
        ans = capacit_series(a, b);
        std::cout << ans;
        break;

    case RESIST_PARALLEL:
        a = 100; //resistance (Ohms)
        b = 200; //resistance (Ohms)
        ans = resist_parallel(a, b);
        std::cout << ans;
        break;

    case FREQUENCY_ANGULAR:
        a = 500; //rads (s−^1)
        ans = freq_W(a);
        std::cout << ans;
        break;

    case OSCILLATING_FREQUENCY:
        a = 0.00005; //inductance (H)
        b = 0.0001; //capacitance (F)
        ans = OscillFreq(a, b);
        std::cout << ans;
        break;

    case QUADRATIC_FORMULA1: //Quadratic formula 1, only testing one because they are identical apart from the (+/-)
        a = 1; 
        b = 20; //b^2 should be greater than (4 x a x c) or this fails
        c = 3;
        ans = quadratForm1(a, b, c);
        std::cout << ans;
        break;

    case ELECTRON_ENERGY:
        a = 0.0381e10; //wave length (m)
        b = 6.1037e-32; //effective mass (kg)
        ans = electronE(a, b);
        std::cout << ans;
        break;

    case EFFECTIVE_ELECTRON_ENERGY:
        a = 0.0381e10; //wave length (m)
        b = 6.1037e-32; //effective mass (kg)
        c = 2.272e-19; //band gap energy (J)
        ans = effElectronE(a, b, c);
        std::cout << ans;
        break;

    case BASE_TWO_LOG:
        a = 16;
        ans = base2_log_calc(a);
        std::cout << ans;
        break;

    case CIRCLE_AREA:
        a = 4;
        ans = circle_Area(a);
        std::cout << ans;
        break;
    }

    return 0;
}

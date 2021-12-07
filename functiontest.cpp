#include <iostream>
#include <string>
#include "functions.h"

double a;
double b;
double c;
double ans;

typedef enum test_names
{
    SUM,
    REACTANCE,
    RELUCTANCE,
    CAPACITANCE_SERIES
} test_t;

test_t test = RELUCTANCE; //Change the test case here

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
        a = 0.00005; //Farad (F)
        b = 0.00005; //Farad (F)
        ans = capacit_series(a, b);
        std::cout << ans;
        break;

        //resist parallel, freq
    }
    
    return 0;
}

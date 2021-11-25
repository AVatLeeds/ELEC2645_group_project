// g++ -Wall raw_byte_print_utility.cpp -o raw_byte_print.exec

#include <iostream>
#include <termios.h>

#define STDIN 0
#define STDOUT 1

char received;

struct termios term_props;
struct termios orig_term_props;

int main()
{
    tcgetattr(STDIN, &term_props);
    orig_term_props = term_props;

    term_props.c_lflag &= ~(ICANON | ECHO | ISIG);
    term_props.c_iflag &= ~(IXON | ICRNL);

    tcsetattr(STDIN, TCSANOW, &term_props);

    while ((received = getchar()))
    {
       printf(" %d ", received);
    }
    
    tcsetattr(STDIN, TCSANOW, &orig_term_props);

    return 0;
}
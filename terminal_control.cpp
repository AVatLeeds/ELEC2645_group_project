#include "terminal_control.h"
#include <termios.h>
#include <stdexcept>

#include <iostream>

#define STDIN 0
#define STDOUT 1
#define STDERR 2

struct termios original_attributes;
int attributes_changed = 0;

void enable_raw_mode()
{
    if (tcgetattr(STDIN, &original_attributes))
    {
        throw std::runtime_error("Error: Failed to read terminal attributes.");
    }

    struct termios raw_mode = original_attributes;
    raw_mode.c_lflag &= ~(ICANON | ECHO | ISIG);
    raw_mode.c_iflag &= ~(IXON | ICRNL);

    if (tcsetattr(STDIN, TCSANOW, &raw_mode))
    {
        throw std::runtime_error("Error: Failed to set raw mode terminal attributes");
    }

    attributes_changed = 1;
}

void disable_raw_mode()
{
    if (attributes_changed)
    {
        if (tcsetattr(STDIN, TCSANOW, &original_attributes))
        {
            throw std::runtime_error("Error: Failed to set original terminal attributes.");
        }
    }
}
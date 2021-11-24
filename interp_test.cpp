#include <iostream>
#include <string>
#include <termios.h>

//some important ANSII escape codes
#define BACKSPACE "\x08"
#define ERASE_IN_LINE "\x1B[K"

#define LEFT_ARROW "\x1B[D"

char received;

std::string command_line;

struct termios stdin_props;

int main()
{
    tcgetattr(0, &stdin_props);

    stdin_props.c_lflag &= ~ICANON;
    stdin_props.c_lflag &= ~ECHO;
    //stdin_props.c_cc[VMIN] = 1;
    //stdin_props.c_cc[VTIME] = 0;

    tcsetattr(0, TCSANOW, &stdin_props);

    while ((received = getchar()))//read(0, &received, 1))
    {
        if (received > 31 && received < 127)
        {
            printf("%c", received);
            command_line.append({received});
        }
        else
        {
            switch (received)
            {
                case 127:
                printf(BACKSPACE);
                printf(ERASE_IN_LINE);
                if (!command_line.empty())
                {
                    command_line.pop_back();    
                }
                break;

                case 10:
                printf("%c%c%c%c\n", 27, 91, 50, 75);
                std::cout << command_line << std::endl;
                command_line.clear();
                break;

                default:
                printf("%d", received);
                break;
            }
        }
        
        //printf("%d", received);
    }

    /*
    //std::cout << ">> ";
    while (std::cin >> command_line)
    {
        std::cout << command_line;// << std::endl;
        //std::cout << ">> ";
    }
    */

    return 0;
}
//some important ANSII escape codes
#include <iostream>
#include <string>

//vvvv Received control codes vvvv
#define LEFT_ARROW      "\x1B[D"
#define RIGHT_ARROW     "\x1B[C"
#define UP_ARROW        "\x1B[A"
#define DOWN_ARROW      "\x1B[B"

#define HOME            "\x1B[H"
#define END             "\x1B[F"

#define PAGE_UP         "\x1B[5~"
#define PAGE_DOWN       "\x1B[6~"

#define INSERT          "\x1B[2~"
#define DELETE          "\x1B[3~"

//vvvv Delivered control codes vvvv
#define BACKSPACE       "\x08"
#define ERASE_IN_LINE   "\x1B[K"
#define ERASE_TO_EOL    "\x1B[K"
#define CURSOR_HOME     "\x1B[0;0H"
#define CURSOR_POS(x, Y)    "\x1B[%d;%dH", (X), (Y)

char * prompt = "lineEd: ";
unsigned int prompt_length = 8;

void LineEd_set_prompt(const char * custom_prompt)
{
    prompt = (char *)custom_prompt;
    unsigned int i = 0;
    while (prompt[i] != '\0') i ++;
    prompt_length = i - 1; //check this
}

/*
void clear_line()
{
    std::cout << CURSOR_HOME;
    std::cout << ERASE_TO_EOL;
    cursor_column = 0;
    command_line.clear();
    line_position = 0;
}
*/

enum states {NORMAL, ESC_SEQ, CTRL_SEQ};

states state = NORMAL;

std::string command_line;
unsigned int line_position = 0;
unsigned int cursor_column = 0;
unsigned int cursor_row = 0;

char in_char;

std::string get_line()
{
    while ((in_char = getchar()))
    {
        switch (state)
        {
            case NORMAL:
            if ((in_char > 0x20 && in_char < 0x7E) || in_char == 0x09)
            {
                command_line.insert(line_position, {in_char});
                line_position ++;
            }
            else
            {
                switch (in_char)
                {
                    case 0x7F:
                    command_line.erase(line_position);
                    break;

                    case 0x08:
                    line_position --;
                    command_line.erase(line_position);
                    break;

                    case 0x0A:
                    case 0x0D:

                    return command_line;
                }
            }
            break;

            case ESC_SEQ:

            break;

            case CTRL_SEQ:

            break;
        }
    }
}

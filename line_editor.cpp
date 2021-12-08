#include <iostream>
#include <string>
#include <list>

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
#define ERASE_LINE      "\x1B[2K"
#define CURSOR_HOME     "\x1B[0;0H"
#define CURSOR_POS(X, Y)    "\x1B["#X";"#Y"H"
#define LINE_HOME       "\x1B[0G" // horizontal move absolute
//#define CURSOR_TO_COLUMN(X) "\x1B["#X"G"
#define CURSOR_LEFT     "\x1B[1D"
#define CURSOR_RIGHT    "\x1B[1C"

void cursor_to_column(unsigned int column)
{
    std::cout << "\x1B[" << column << "G";
}

std::list<std::string> cmd_history;
std::list<std::string>::iterator cmd_history_ptr = cmd_history.begin();
std::string prompt = "-> ";
std::string cmd_line;

bool edit_flag, insert_mode;
unsigned int line_position = 0;
char in_char;

void visual_erase()
{
    std::cout << ERASE_LINE;
    std::cout << LINE_HOME; 
}

void visual_re_print()
{
    visual_erase();
    std::cout << prompt << cmd_line;
    cursor_to_column(prompt.length() + 1  + line_position);
}

std::string get_line()
{
    edit_flag = false;
    insert_mode = false;
    cmd_history_ptr = cmd_history.end();
    cmd_line.clear();
    std::cout << prompt;

    while ((in_char = getchar()))
    {
        if ((in_char > 0x1F && in_char < 0x7F) || in_char == 0x09)
        {
            if (insert_mode && (line_position < cmd_line.length()))
            {
                cmd_line[line_position] = in_char;
            }
            else
            {
                cmd_line.insert(line_position, {in_char});
            }
            line_position ++;
            edit_flag = true;
        }
        else
        {
            switch (in_char)
            {
                // For some reason backspace sends character 127 (delete) instead of 8 (backspace).
                // Can't seem to change this so making both do the same thing.
                case 0x08:
                case 0x7F:
                line_position = line_position ? line_position - 1 : 0;
                cmd_line.erase(line_position, 1);
                break;

                case 0x0A:
                case 0x0D:
                line_position = 0;
                visual_erase();
                if (edit_flag)
                {
                    cmd_history.push_back(cmd_line);
                    cmd_history_ptr = cmd_history.end();
                }
                return cmd_line;
                break;

                case 0x03:
                line_position = 0;
                visual_erase();
                throw std::runtime_error("Program terminated on ctrl-c.");
                break;

                case 0x1B:
                in_char = getchar();
                if (in_char == '[')
                {
                    in_char = getchar();
                    switch (in_char)
                    {
                        case 'A':
                        if (cmd_history_ptr != cmd_history.begin())
                        {
                            cmd_history_ptr --;
                            cmd_line = *cmd_history_ptr;
                            line_position = cmd_line.length();
                        }
                        break;

                        case 'B':
                        if (cmd_history_ptr != (-- cmd_history.end()))
                        {
                            cmd_history_ptr ++;
                            cmd_line = *cmd_history_ptr;
                            line_position = cmd_line.length();
                        }
                        break;

                        case 'C':
                        if (line_position < cmd_line.length())
                        {
                          line_position ++;
                        }
                        break;

                        case 'D':
                        if (line_position)
                        {
                          line_position --;
                        }
                        break;

                        case 'H':
                        line_position = 0;
                        break;

                        case 'F':
                        line_position = cmd_line.length();
                        break;

                        case '2':
                        in_char = getchar();
                        if (in_char == '~')
                        {
                            insert_mode = insert_mode ? false : true;
                        }
                        break;

                        case '3':
                        in_char = getchar();
                        if (in_char == '~')
                        {
                            cmd_line.erase(line_position, 1);
                        }
                        break;

                        case '5':
                        in_char = getchar();
                        if (in_char == '~')
                        {
                            // Page Up
                        }
                        
                        break;

                        case '6':
                        in_char = getchar();
                        if (in_char == '~')
                        {
                            // Page Down
                        }
                        break;
                    
                        default:

                        break;
                    }
                }
                break;

                default:
                printf("%c", in_char);
                break;
            }
        }
        visual_re_print();
    }
}

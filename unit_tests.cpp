#include <iostream>
#include <string>
#include "terminal_control.h"
#include "line_editor.h"

typedef enum test_names
{
    PLACEHOLDER,
    ENABLE_RAW_MODE,
    DISABLE_RAW_MODE,
    RAW_MODE_SETTINGS,
    GET_LINE
} test_t;

test_t test = GET_LINE;

int main()
{
    switch (test)
    {
        case PLACEHOLDER:
        break;
        
        case ENABLE_RAW_MODE:
        try
        {
            enable_raw_mode();
        }
        catch(std::runtime_error * error)
        {
            std::cerr << error->what() << std::endl;
        }
        break;

        case DISABLE_RAW_MODE:
        try
        {
            enable_raw_mode();
        }
        catch(std::runtime_error * error)
        {
            std::cerr << error->what() << std::endl;
        }
        break;

        case RAW_MODE_SETTINGS:
        try
        {
            enable_raw_mode();
            disable_raw_mode();
        }
        catch(std::runtime_error * error)
        {
            std::cerr << error->what() << std::endl;
        }
        break;

        case GET_LINE:
        try
        {
            int run = 1;
            std::string line;
            enable_raw_mode();
            while (run)
            {
                line = get_line();
                if (line == "END") run = 0;
                std::cout << line << std::endl;
            }
            disable_raw_mode();
        }
        catch(std::runtime_error * error)
        {
            std::cerr << error->what() << std::endl;
        }
        break;

        default:
        break;
    }
    
    return 0;
}
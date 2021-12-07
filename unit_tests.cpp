#include <iostream>
#include <string>
#include <list>
#include "terminal_control.h"
#include "line_editor.h"

typedef enum test_names
{
    PLACEHOLDER,
    ENABLE_RAW_MODE,
    DISABLE_RAW_MODE,
    RAW_MODE_SETTINGS,
    GET_LINE,
    MATCH_ONLY_WORD
} test_t;

test_t test = MATCH_ONLY_WORD;

enum token_type
{
    COMMAND_WORD,
    NUMBER,
    OPERATOR,
    SEPARATOR
};

enum command_words
{
    ADD,
    SUB,
    MUL,
    DIV,
    ABS,
    MOD,
    NOT,
    AND,
    OR,
    XOR,
    IF,
    FOR,
    DO,
    WHILE,
    DUP,
    SWAP,
    PUSH,
    POP,
    ROLL,
    PRINT,
    DEF,
    HELP,
    QUIT
};

std::list<std::string> command_words = {"add", "sub", "mul", "div", "abs", "mod", "not", "and", "or", "xor", "if", "for", "do", "while", "dup", "swap", "push", "pop", "roll", "print", "def", "help", "quit"};

struct token_list_node
{
  enum token_type is;
  unsigned int length;
  std::string literal_string; // just for test
  std::string symbol;
  enum command_words command_word;
  double number;
  std::string string;
};

unsigned int match_only_word(std::string in_string, std::string to_match)
{
    unsigned int i;
    if (to_match.length() > in_string.length())
    {
        return 0;
    }
    for (i = 0; i < to_match.length(); i ++)
    {
        if (to_match[i] != in_string[i])
        {
            return 0;
        }
    }
    //i ++;
    if ((i == in_string.length()) || !isalpha(in_string[i]))
    {
        return -- i;
    }
    return 0;
}

bool find_command_words(std::string command_line, std::list<struct token_list_node> * token_list)
{
    unsigned int i = 0;
    std::list<std::string>::iterator words_iter = command_words.begin();
    struct token_list_node node;
    unsigned int length;
    unsigned int greatest_length = 0;
    // this is CRUSTY. Please fix
    unsigned int index = 0;
    unsigned int index_of_greatest_length;
    
    // traverse to first alphabetic character
    while ((i < command_line.length()) && !isalpha(command_line[i]))
    {
        i ++;
    }
    // iterate over the command words
    for (words_iter = command_words.begin(); words_iter != command_words.end(); words_iter ++)
    {
        //attempt to find largest matching command word at this index
        length = match_only_word(command_line.substr(i), *words_iter);
        if (length > greatest_length)
        {
            greatest_length = length;
            index_of_greatest_length = index;
            node.literal_string = *words_iter;
        }
        index ++;
    }
    i += (greatest_length + 1);
    // couldn't find any command words here
    if (greatest_length == 0)
    {
        while ((i < command_line.length()) && isalpha(command_line[i]))
        {
            i ++;
        }
        find_command_words(command_line.substr(i), token_list);
    }
    // largest possible command word found
    else
    {
        node.is = COMMAND_WORD;
        node.length = greatest_length;
        node.command_word = (enum command_words)index_of_greatest_length;
        token_list->push_back(node);
        if (i < command_line.length())
        {
            find_command_words(command_line.substr(i), token_list);
        }
        return 1;
    } 
}

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

        case MATCH_ONLY_WORD:
        try
        {
            int run = 1;
            int length;
            std::string line;
            std::list<struct token_list_node> token_list;
            std::list<struct token_list_node>::iterator list_itr;
            std::list<std::string>::iterator command_word = command_words.begin();
            enable_raw_mode();
            while (run)
            {
                line = get_line();
                if (line == "END") run = 0;
                //length = match_only_word(line, "add");
                find_command_words(line, &token_list);
                for(list_itr = token_list.begin(); list_itr != token_list.end(); list_itr ++)
                {
                    std::cout << list_itr->literal_string << std::endl;
                }
                token_list.clear();
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
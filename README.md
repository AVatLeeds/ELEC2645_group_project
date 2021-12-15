# ELEC 2645 Embedded systems - group project

### To compile this project:

g++ -Wall terminal_control.cpp line_editor.cpp tokenizer.cpp RP_parser.cpp parser.cpp parser_wrapper.cpp stack.cpp main.cpp -o calculator.exec

## Scope:

From the unit 2 group project page
> During the group project, you will work in groups consisting of 3 members to develop a menu-driven command line tool. This should be of a technical nature e.g. an engineering calculator. Each member of your team should take ownership of a single menu item and develop a program the demonstrates your understanding of the topics covered in Unit 1. For example, one member may do a resistor calculator, another an op-amp calculator and the final member a filter calculator."

My suggestion for this project is that we create an extensible command driven application for performing various calculations. The application would feature a command interpreter (in the same vein as the Python interpreter for instance) and a simple, extensible scripting language. In this way our application could be tailored to a variety of different jobs with minimum effort.

I suggest, for ease of implementation, that we use [Reverse Polish notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation) for the scripting language. 

## User requirements:

-   Capability to perform all basic arithmetic operations.
-   More complex mathematical operations built in, such as those found in "math.h" or "cmath".
-   Built in numerical constants, such as those found in "math.h" or "cmath".
-   Line editing.
-   Command history / command recall.
-   Capability to define custom commands.
-   Capability to load scripts to a file.
-   Capability to save custom commands to a file.

## Technical requirements:

-   Platform agnosticism (can be easily ported to any system, including embedded systems).
-   POSIX compliant control code interface (complies with [BS ISO-IEC 6429:1992](https://shop.bsigroup.com/products/information-technology-control-functions-for-coded-character-sets)).

---

## License

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License</a>.
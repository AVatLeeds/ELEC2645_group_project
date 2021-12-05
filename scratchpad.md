# Notes

-   "termios.h" man page: [https://man7.org/linux/man-pages/man3/termios.3.html](https://man7.org/linux/man-pages/man3/termios.3.html). Useful information on the C <-> POSIX interface for controlling virtual terminals.

-   Info on POSIX shell line editing modes: [https://sites.ualberta.ca/dept/chemeng/AIX-43/share/man/info/C/a_doc_lib/aixuser/usrosdev/inline_edit_korn.htm](https://sites.ualberta.ca/dept/chemeng/AIX-43/share/man/info/C/a_doc_lib/aixuser/usrosdev/inline_edit_korn.htm). Is there an official POSIX standard for line editing?

-   Very useful article on manipulating the termios struct: [https://viewsourcecode.org/snaptoken/kilo/02.enteringRawMode.html](https://viewsourcecode.org/snaptoken/kilo/02.enteringRawMode.html).

    -   the control key maps the letters A to Z to bytes 1 - 26.
    -   ctrl-c and ctrl-z which sent SIGINT and SIGSTP respectively are controlled by the ISIG flag.
    -   ctrl-s and ctrl-q are used for software flow control (XON and XOFF) and can be controlled via the IXON flag.
    -   

from [https://vt100.net/docs/vt510-rm/chapter4.html](https://vt100.net/docs/vt510-rm/chapter4.html):

-   The ascii character table is as follows:

| ASCII table | 0  | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:-----------:|:--:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| 0           |NULL|DLE|SP |0  |@  |P  |`  |p  |
| 1           |SOH |DC1|!  |1  |A  |Q  |a  |q  |
| 2           |STX |DC2|"  |2  |B  |R  |b  |r  |
| 3           |ETX |DC3|#  |3  |C  |S  |c  |s  |
| 4           |EOT |DC4|$  |4  |D  |T  |d  |t  |
| 5           |ENQ |NAK|%  |5  |E  |U  |e  |u  |
| 6           |ACK |SYN|&  |6  |F  |V  |f  |v  |
| 7           |BELL|ETB|'  |7  |G  |W  |g  |w  |
| 8           |BS  |CAN|(  |8  |H  |X  |h  |x  |
| 9           |TAB |EM |)  |9  |I  |Y  |i  |y  |
| A           |LF  |SUB|*  |:  |J  |Z  |j  |z  |
| B           |VF  |ESC|+  |;  |K  |[  |k  |{  |
| C           |FF  |FS |,  |<  |L  |\  |l  |\| |
| D           |CR  |GS |-  |=  |M  |]  |m  |}  |
| E           |SO  |RS |.  |>  |N  |^  |n  |~  |
| F           |SI  |US |/  |?  |O  |_  |o  |DEL|

-   An ANSI escape sequence is characterised by the ESC (0x1B), followed by zero or more characters from column 2 (0x20 to 0x2F), followed by a single character from the range 0x30 to 0x7E. 

    Using the above rule an ANSI escape code can be parsed from any other ordinary incoming text.

-   ANSI control sequences start with the control sequence introducer character (0x9B), however, in 7-bit serial mode characters above 0x7F are not available. In this case the sequence of 7-bit characters "ESC" and "[" (0x1B and 0x5B) is used in place of the control sequence introducer.

    The rest of the control sequence is characterised by zero or more parameter characters (0x30 to 0x3F) (multiple parameters can be provided but them must be separated by the semicolon character (0x3B)), followed by zero or more characters from column 2 (0x20 to 0x2F), followed by a single character from the range 0x30 to 0x7E.

### Software architecture:
-   enable raw mode
-   read character loop
    -   command history
    -   line editor
        -   tokenizer
            -   parser
            -   stack
            -   calculation functions
-   disable raw mode
-   return

## Tokenizer specification

-   a function
-   takes the command line, a std::string, as the input argument
-   returns a C++ linked list of tokens, where a token is:
    -   each space separated item in the command line is a token
    -   tokens can be numbers or command words

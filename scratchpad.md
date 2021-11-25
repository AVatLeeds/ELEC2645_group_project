# Notes

-   "termios.h" man page: [https://man7.org/linux/man-pages/man3/termios.3.html](https://man7.org/linux/man-pages/man3/termios.3.html). Useful information on the C <-> POSIX interface for controlling virtual terminals.

-   Info on POSIX shell line editing modes: [https://sites.ualberta.ca/dept/chemeng/AIX-43/share/man/info/C/a_doc_lib/aixuser/usrosdev/inline_edit_korn.htm](https://sites.ualberta.ca/dept/chemeng/AIX-43/share/man/info/C/a_doc_lib/aixuser/usrosdev/inline_edit_korn.htm). Is there an official POSIX standard for line editing?

-   Very useful article on manipulating the termios struct: [https://viewsourcecode.org/snaptoken/kilo/02.enteringRawMode.html](https://viewsourcecode.org/snaptoken/kilo/02.enteringRawMode.html).
    -   the control key maps the letters A to Z to bytes 1 - 26.
    -   ctrl-c and ctrl-z which sent SIGINT and SIGSTP respectively are controlled by the ISIG flag.
    -   ctrl-s and ctrl-q are used for software flow control (XON and XOFF) and can be controlled via the IXON flag.
    -   


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
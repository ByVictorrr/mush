# mush - The Minimally Useful SHell

This assignment requires you to write a simple shell. mush has nowhere near the functionality of a
full-blown shell like /bin/sh or /bin/csh, but it is fairly powerful for its size and has most features
that one would want in a shell, including:

• Both interactive and batch processing. If mush is run with no argument it reads commands from stdin until an end of file (^D) is typed. If mush is run with an argument, e.g.
“mush foofile,” it will read its commands from foofile.
This may not be accomplished by duping the file to stdin. It is important to retain the
original standard input for executed pipelines, otherwise a script starting with the line cat
would proceed to cat the rest of the script.

• Support for redirection. mush supports redirection of standard in (<) and standard out (>)
from or into files. mush also supports pipes (|) to connect the standard output of one command
to the standard input of the following one.

• A built-in cd command. Recall that cd cannot be run as a child process because it would
change the child’s working directory, not the parent’s.

• Support for SIGINT. When the interrupt character (ˆC) is typed, mush catches the resulting
SIGINT and responds appropriately. That is, the shell doesn’t die, but it should wait for any
running children to terminate and reset itself to a sane state.

## Usage
make

./mush [shell script]


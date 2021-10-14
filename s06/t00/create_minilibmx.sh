#!/bin/ssh

clang -std=c11 -Wall -Wextra -Werror -Wpedantic -c *.c
ar rcs minilibmx.a *.o
rm -f *.o


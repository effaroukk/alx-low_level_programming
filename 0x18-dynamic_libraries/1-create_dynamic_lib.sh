#!/bin/bash
gcc -fPIC -c *.c
gcc -shared -o liball.so *.o
gcc -Wall -Wextra -Werror -pedantic -c -fPIC *.c
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

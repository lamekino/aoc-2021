#!/bin/sh

echo cc -Wall -Wextra -pedantic -o solution solution.c
cc -Wall -Wextra -pedantic -o solution solution.c
# if [ -x "solution" ]; then
#     echo ./solution < example
#     ./solution < example

#     rm solution
# fi

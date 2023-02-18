#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdatomic.h>

#include "read.h"
#include "eval.h"
#include "print.h"
#include "help.h"

// Tentative name: FuncS, Functional Shell

atomic_bool quit = 0;

int main(int argc, char *argv[])
{
    /* Main loop:
     * REPL
     * Also have a shell language
     */

    int r = 0;

    char line[MAX_LINE];
    char result[MAX_LINE];
    char **tokens;

    while (!quit) {
        r = read(line, tokens);
        r = eval(tokens,result);
        r = print(result);
    }

    return r;
}
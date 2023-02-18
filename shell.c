#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdatomic.h>

#include "read.h"
#include "eval.h"
#include "print.h"
#include "commands.h"
#include "help.h"
#include "environment.h"

// Tentative name: FuncS, Functional Shell

atomic_bool quit = 0;

int main(int argc, char *argv[])
{
    /* Main loop:
     * REPL
     * Also have a shell language
     */

    init_table();

    int r = 0;

    char line[MAX_LINE];
    char result[MAX_LINE];
    memset(result, 0, MAX_LINE);
    char **tokens;
    int n_tokens = 0;
    system("cls");
    printf("%s > ", ENV.USERNAME);
    while (!quit) {
        r = read(line, &n_tokens, &tokens);
        r = eval(tokens, n_tokens, result, &quit);
        r = print(result);
    }

    return r;
}
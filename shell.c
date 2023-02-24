#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdatomic.h>
#include <unistd.h>

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
    char *p = malloc(MAX_LINE);
    if (p == NULL) {
        return -1;
    }
    if (getcwd(p, MAX_LINE) == NULL) {
        return -1;
    }
    strcpy(ENV.path, p);
    chdir(ENV.path);
    system("clear");
    while (!quit) {
        r = print(result);
        r = readl(line, &n_tokens, &tokens);
        r = eval(tokens, n_tokens, result, &quit);
    }

    return r;
}
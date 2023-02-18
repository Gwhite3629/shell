#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdatomic.h>

#include "environment.h"
#include "commands.h"
#include "eval.h"
#include "help.h"

int eval(char **tokens, int n_tokens, char *result, atomic_bool *quit)
{
    if (n_tokens <= 0) {
        return 0;
    }

    command_t temp;
    temp = lookup(tokens[0]);

    if (temp.hash == 0) {
        printf("Invalid command: %s\n", tokens[0]);
    }

    switch (temp.id) {
        case 0: // EXIT
            (*quit) = 1;
            printf("Exiting\n");
            break;
        case 1: // PRINT
            for (int i = 1; i < n_tokens; i++) {
                printf("%s ", tokens[i]);
            }
            printf("\n");
            break;
        case 2: // HELP
            printf("\
EXIT:\n\tExit the program\n\
PRINT:\n\tPrint the rest of the line\n\
HELP:\n\tDisplay this prompt\n\
CLEAR:\n\tClear the screen\n\
USER:\n\tSet username\n\
PWD:\n\tDisplay current directory path\n\
");
            break;
        case 3: // CLEAR
            system("cls"); // try "clear" on linux
            break;
        case 4: // USER
            if (n_tokens < 2) {
                printf("Invalid Username\n");
                return 0;
            } else {
                strcpy(ENV.USERNAME, tokens[1]);
            }
            break;
        case 5: // PWD
            
            break;
        default:
            break;
    };

    return 0;
}
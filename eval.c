#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdatomic.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "environment.h"
#include "commands.h"
#include "eval.h"
#include "help.h"
#include "file.h"

int eval(char **tokens, int n_tokens, char *result, atomic_bool *quit)
{
    pid_t c;

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
exit:\n\tExit the program\n\
print:\n\tPrint the rest of the line\n\
help:\n\tDisplay this prompt\n\
clear:\n\tClear the screen\n\
user:\n\tSet username\n\
pwd:\n\tDisplay current directory path\n\
cd:\n\tChange Directory\n\
ls:\n\tList files\n\
bash:\n\tOpen the BASH shell\n\
");
            break;
        case 3: // CLEAR
            system("clear"); // try "clear" on linux, cls on windows
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
            printf("%s\n", ENV.path);
            break;
        case 6: // CD
            if (n_tokens < 2) {
                printf("Invalid: No target directory\n");
            } else if (!strcmp(tokens[1], "..") | !strcmp(tokens[1], "../"))
            {
                if (!strcmp(ENV.path, "/")) {
                    printf("Invalid: Already in root\n");
                } else {
                    char *tmp = strrchr(ENV.path, '/');
                    memset(tmp, '\0', strlen(tmp));
                    if (tmp == ENV.path) {
                        ENV.path[0] = '/';
                    }
                }
            } else if (!strcmp(tokens[1], ".") | !strcmp(tokens[1], "./")) {

            } else if (tokens[1][0] == '/') {
                int v = verify_absolute(tokens[1]);
                if (v == 1) {
                    strcpy(ENV.path, tokens[1]);
                } else {
                    printf("Invalid: Can't find dir\n");
                }
            } else {
                int v = verify_path(tokens[1]);
                if (v == 1) {
                    strcat(ENV.path, "/");
                    strcat(ENV.path, tokens[1]);
                } else {
                    printf("Invalid: Can't find dir\n");
                }
            }
            chdir(ENV.path);
            break;
        case 7: // LS
            c = fork();
            if (0 == c)
                execv("/bin/ls", tokens);
            wait(NULL);
            break;
        case 8: // bash
            c = fork();
            if (0 == c)
                execv("/bin/bash", tokens);
            wait(NULL);
            break;
        default:
            break;
    };

    return 0;
}

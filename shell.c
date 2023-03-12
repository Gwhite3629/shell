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
#include "path.h"
#include "file.h"
#include "config.h"

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

    path_t *path_table = NULL;
    config_t cfg;
    int size;

    strcpy(ENV.home, getenv("HOME"));

    r = read_path(&path_table, &size);
    if (r < 0) {
        printf("Failed to load path\n");
        return -1;
    }

    r = read_config(&cfg);

    char line[MAX_LINE];
    char **tokens = NULL;
    int n_tokens = 0;
    char *p = malloc(MAX_LINE);
    if (p == NULL) {
        printf("Failed to allocate\n");
        return -1;
    }
    if (getcwd(p, MAX_LINE) == NULL) {
        return -1;
    }
    strcpy(ENV.path, p);
    chdir(ENV.path);

    tokens = malloc(sizeof(char *)*1);
    if (tokens == NULL) {
        r = -1;
        return r;
    }

    tokens[0] = malloc(sizeof(char)*32);
    if (tokens[0] == NULL) {
        r = -1;
        return r;
    }
    memset(tokens[0], 0, sizeof(char)*32);

    strcpy(ENV.USERNAME, cfg.username);

    system("clear");
    while (!quit) {
        r = print(cfg);
        r = readl(line, &n_tokens, &tokens);
        r = eval(tokens, n_tokens, &quit, &path_table, &size, &cfg);
        for (int i = 1; i < n_tokens; i++) {
            free(tokens[i]);
        }
        memset(tokens[0], 0, 32);
    }

    if (tokens) {
        if (tokens[0])
            free(tokens[0]);
        free(tokens);
    }
    if (path_table)
        free(path_table);
    if (p)
        free(p);

    return r;
}

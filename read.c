#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read.h"
#include "help.h"

int read(char *line, int *n_tokens, char ***tokens) {
    int r = 0;

    memset(line, 0, MAX_LINE);

    fgets(line, MAX_LINE, stdin);

    r = parse(line, n_tokens, tokens);

    return r;
}

int parse(char *line, int *n_tokens, char ***tokens)
{
    int r = 0;
    (*tokens) = malloc(sizeof(char *)*1);
    if ((*tokens) == NULL) {
        r = -1;
        return r;
    }

    (*tokens)[0] = malloc(sizeof(char)*32);
    if ((*tokens)[0] == NULL) {
        r = -1;
        return r;
    }
    memset((*tokens)[0], 0, sizeof(char)*32);

    char *t = line;
    int wc = 1;
    int c_count = 0;

    while(t != NULL) {
        if (*t == ' ') {
            (*tokens) = realloc((*tokens), sizeof(char *) * (wc++));
            (*tokens)[wc-1] = malloc(sizeof(char)*32);
            memset((*tokens)[wc-1], 0, sizeof(char)*32);
            c_count = 0;
        } else if (*t == '\n') {
            (*n_tokens) = wc;
            return r;
        }
        else {
            (*tokens)[wc-1][c_count] = *t;
            c_count++;
        }
        t++;
    }
    (*n_tokens) = wc;
    return r;
}
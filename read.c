#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read.h"
#include "help.h"

int read(char *line, char **tokens) {
    int r = 0;

    memset(line, 0, MAX_LINE);

    fgets(line, MAX_LINE, stdin);

    r = parse(line, tokens);

    return r;
}

int parse(char *line, char **tokens)
{
    int r = 0;

    return r;
}
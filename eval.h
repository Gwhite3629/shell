#ifndef EVAL_H
#define EVAL_H

#include <stdatomic.h>

#include "help.h"

int eval(char **tokens, int n_tokens, char *result, atomic_bool *quit);

#endif // EVAL_H
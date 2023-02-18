#ifndef HELP_H
#define HELP_H

#define MAX_LINE 4096

typedef enum eval_type {SCRIPT, PROGRAM, COMMAND} eval_type;

typedef struct eval_t {
    eval_type type;
} eval_t;

#endif // HELP_H
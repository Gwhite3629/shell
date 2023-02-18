#ifndef COMMANDS_H
#define COMMANDS_H

typedef struct command_t {
    char name[32];
    int hash;
} command_t;

#define SIZE 2

extern command_t COMMANDS;

#endif // COMMANDS_H
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

typedef struct environment_t {
    char USERNAME[32];
} environment_t;

extern environment_t ENV;

#endif // ENVIRONMENT_H
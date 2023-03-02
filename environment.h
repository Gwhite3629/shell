#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

typedef struct environment_t {
    char USERNAME[32];
    char path[4096];
    char home[4096];
} environment_t;

extern environment_t ENV;

#endif // ENVIRONMENT_H
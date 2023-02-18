#ifndef HELP_H
#define HELP_H

#define MAX_LINE 4096

typedef enum eval_type {SCRIPT, PROGRAM, COMMAND} eval_type;

typedef struct eval_t {
    eval_type type;
} eval_t;

static inline unsigned long
hash(char *name)
{
	unsigned long val = 5381;
	int c;
	while ((c = *name++)) {
		val = ((val << 5) + val) + c;
	}
	return (int)(val % (__INT_MAX__));
}

#endif // HELP_H
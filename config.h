#ifndef CONFIG_H
#define CONFIG_H

typedef struct config_t {
    char username[32];
    int name_color;
    int path_color;
} config_t;

int read_config(config_t *cfg);

int write_config(config_t *cfg);

#endif // CONFIG_H

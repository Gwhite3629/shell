#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "config.h"
#include "environment.h"

int read_config(config_t *cfg)
{
    FILE *config_file;
    int r = 0;
    char p[4096];

    strcpy(p,ENV.home);
    strcat(p,"/.Fconfig");

    config_file = fopen(p, "r");
    if (config_file == NULL) {
        printf("Failed to open file\n");
        perror(strerror(errno));
        return -1;
    }

    fscanf(config_file, "user: %s\n", cfg->username);
    fscanf(config_file, "ncolor: %d\n", &cfg->name_color);
    fscanf(config_file, "pcolor: %d\n", &cfg->path_color);

    fclose(config_file);

    return r;
}

int write_config(config_t *cfg)
{
    FILE *config_file;
    int r = 0;
    char p[4096];

    strcpy(p,ENV.home);
    strcat(p,"/.Fconfig");

    config_file = fopen(p, "w");
    if (config_file == NULL) {
        printf("Failed to open file\n");
        perror(strerror(errno));
        return -1;
    }

    fprintf(config_file, "user: %s\n", cfg->username);
    fprintf(config_file, "ncolor: %d\n", cfg->name_color);
    fprintf(config_file, "pcolor: %d\n", cfg->path_color);

    fclose(config_file);

    return r;
}

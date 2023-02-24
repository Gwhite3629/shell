#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

#include "file.h"
#include "environment.h"

int verify_path(char *path)
{
    char u_path[4096];

    strcpy(u_path, ENV.path);

    strcat(u_path, "/");
    strcat(u_path, path);

    DIR *r = opendir(u_path);
    if (r != NULL) {
        return 1;
    }

    return 0;
}

int verify_absolute(char *path)
{
    DIR *r = opendir(path);
    if (r != NULL) {
        return 1;
    }
    return 0;
}
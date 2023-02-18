#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "print.h"
#include "help.h"
#include "environment.h"

int print(char *result)
{
    printf("%s > ", ENV.USERNAME);
    
    return 0;
}
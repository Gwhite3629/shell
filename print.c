#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "print.h"
#include "help.h"
#include "environment.h"

int print(void)
{
    printf("%s%s%s:%s%s%s > ", KCYN, ENV.USERNAME, KNRM, KMAG, ENV.path, KNRM);
    
    return 0;
}
#include <stdio.h>
#include <string.h>

#include "encrypt.h"

#define BUFSIZE 80

int main()
{
    char test[BUFSIZE];

    while(fgets(test, BUFSIZE, stdin)) {
        test[strlen(test) - 1] = '\0';
        encrypt(test);
        printf("%s\n", test);
    }

    return 0;
}
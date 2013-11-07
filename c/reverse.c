#include <stdio.h>
#include <string.h>
#define BUFSIZE 20

void print_reverse(char *s)
{
    size_t len = strlen(s);

    char *t = s + len - 1;

    while (t >= s) {
        printf("%c", *t);
        t = t - 1;
    }

    puts("");
}

int main()
{
    char str[BUFSIZE];

    fgets(str, BUFSIZE, stdin);
    str[strlen(str) - 1] = '\0';
    print_reverse(str);
    return 0;
}
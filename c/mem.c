#include <stdio.h>
#include <stdlib.h>

int main(){
    long int max = 1073741824;
    printf("%ld\n", max);

    char *foo;
    long int i;
    foo = (char*) malloc(max * sizeof(char));
    for(i = 0; i < max; i++){
        foo[i] = 1;
    }
    getchar();
}
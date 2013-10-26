#include <stdio.h>
#include <stdlib.h>

int main(){
    char *ptr = "foo";
    printf("Addr of ptr (heap?): %p \nAddr of ptr[1]: %p\n", ptr, &ptr[1]);

    char ptr2[3] = "foo";
    printf("Addr of ptr2 (stack?): %p \nAddr of ptr2[1]: %p\n", ptr2, &ptr2[1]);

    int *ptr3;
    int n;
    n = 3;

    ptr3 = malloc(n * sizeof(int));

    printf("Addr of ptr3 (heap!): %p\n", ptr3);
    printf("So, *ptr = \"foo\" get allocated on the heap, while ptr[3] gets allocated on the stack\n");
    scanf("%d", &n);
    return 0;
}

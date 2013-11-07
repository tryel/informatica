#include <stdio.h>
#include "numeri.h"

int main()
{
    int n;

    puts("Inserisci un numero: ");
    scanf("%d", &n);

    n = decrement(increment(increment(n)));
    printf("Risultato: %d\n", n);

    return 0;
}
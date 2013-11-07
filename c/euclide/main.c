/* Author: Roberto D'Auria
 * Implementation of the (Extended) Euclidean Algorithm
 *
 * main.c
 */

#include <stdio.h>
#include "euclide.h"

int main()
{
    int n1;
    int n2;
    int mcd;
    int x, y;

    int mem_table[3][5];

    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            mem_table[i][j] = 0;
        }
    }

    puts("Inserisci il primo numero:");
    scanf("%d", &n1);

    puts("Inserisci il secondo numero:");
    scanf("%d", &n2);

    mcd = MCD(n1, n2, mem_table, &x, &y);

    printf("MCD(%d, %d) = %d\n", n1, n2, mcd);
    printf("Soluzioni dell'equazione %dx + %dy = %d:\n", n1, n2, mcd);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
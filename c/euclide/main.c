/* Author: Roberto D'Auria
 * Implementation of the (Extended) Euclidean Algorithm
 *
 * main.c
 */

#include <stdio.h>
#include <time.h>

#include "euclide.h"
#include "timediff.h"

int main()
{
    int n1;
    int n2;
    int mcd;
    int x, y;
    struct timespec ts1;
    struct timespec ts2;
    struct timespec res;

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

    clock_gettime(CLOCK_REALTIME, &ts1);
    mcd = MCD(n1, n2, mem_table, &x, &y);
    clock_gettime(CLOCK_REALTIME, &ts2);

    res = diff(ts1, ts2);

    printf("secs: %d, nsecs: %d\n", res.tv_sec, res.tv_nsec);

    printf("MCD(%d, %d) = %d\n", n1, n2, mcd);
    printf("Soluzioni dell'equazione %dx + %dy = %d:\n", n1, n2, mcd);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
/*
 * Author: Roberto D'Auria
 *
 * Example to show the difference between passing parameters
 * by value or by reference.
 *
 */

#include <stdio.h>


void go_south_east(int *lat, int *lon)
{
    printf("%p\n", lat);
    printf("%p\n", lon);
    *lat = *lat - 1;
    *lon = *lon + 1;
}

int main(){
    int latitude = 32;
    int longitude = -64;
    go_south_east(&latitude, &longitude);
    printf("Now at: (%i, %i)\n", latitude, longitude);

    return 0;
}

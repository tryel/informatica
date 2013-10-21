#include <stdio.h>

int main(){
    int n = 0;
    int m = 1;
    int f = 0;
    printf("%d %d ", n, m);
    while(n <= 55000){
        f = n + m;
        printf("%d ", f);
        n = m;
        m = f;
    }
    return 0;
}

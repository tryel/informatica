#include <stdio.h>

int hai_vinto(int n){
    if (n > 50)
        return 0;
    else
        return 1;
}
int main(){
    int n, vinto;

    do {
        printf("Inserisci un numero: ");
        scanf("%d", &n);

        vinto = hai_vinto(n);

        if (vinto && n)
            printf("Hai vinto\n");
        if (!vinto && n)
            printf("Hai perso\n");
    } while(n != 0);

    return 0;
}
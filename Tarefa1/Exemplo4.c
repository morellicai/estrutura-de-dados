#include <stdio.h>
int main(void){
    int n, f;
    printf("Numero? ");
    scanf("%d", &n);
    f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    printf("Fatorial de %d! = %d\n", n, f);
}
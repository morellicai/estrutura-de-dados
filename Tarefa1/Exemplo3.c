#include <stdio.h>
int main(void){
    int p;
    printf("Placa? ");
    scanf("%d", &p);
    switch (p % 10){
    case 1: case 2: puts("Segunda-Feira"); break;
    case 3: case 4: puts("Terca-Feira"); break;
    case 5: case 6: puts("Quarta-Feira"); break;
    case 7: case 8: puts("Quinta-Feira"); break;
    default: puts("Sexta-Feira");
    }
}
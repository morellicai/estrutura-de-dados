# include <stdio.h>
// Passagem por valor
void troca(int a, int b){
    printf("Antes da troca por valor: \na = %d\nb = %d\n", a, b);
    int c = a;
    a = b;
    b = c;
    printf("Depois da troca por valor: \na = %d\nb = %d\n", a, b);
}

// Passagem por referência
void troca2(int *a, int *b){
    printf("Antes da troca por referência: \na = %d\nb = %d\n", *a, *b);
    int c = *a;
    *a = *b;
    *b = c;
    printf("Depois da troca por referência: \na = %d\nb = %d\n", *a, *b);
}

int main(void){
    int x = 3;
    int y = 5;
    troca(x, y);
    troca2(&x, &y);
    return 0;
}
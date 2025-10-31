# include <stdio.h>

int main(void){
    int v = 5;
    int *p = &v;
    printf("Valor de v: %d\n", v);
    printf("Endereco de v: %p\n", (void*)&v);
    printf("Emdereco de p: %p\n", (void*)p);
    printf("Valor apontado por p: %d\n", *p);
    *p = *p + 2;
    printf("Novo valor de v: %d\n", v);
    return 0;
}
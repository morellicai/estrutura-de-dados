# include <stdio.h>

typedef struct {
    float x;
    float y;
} Ponto;

int main(void){
    Ponto p = {1.5, 2.5};
    printf("Ponto p: (%.1f, %.1f)\n", p.x, p.y);
    return 0;
}
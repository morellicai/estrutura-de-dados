#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
    srand(time(NULL));
    int c, n = rand() % 7 + 1;
    do {
        printf("Chute entre 1 e 7: ");
        scanf("%d", &c);
        if(c < n) printf("Chute maior\n");
        else if(c > n) printf("Chute menor\n");
    } while(n != c);
    printf("Acertou!\n");
    return 0;
}
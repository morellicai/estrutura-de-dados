# include <stdio.h>

void barras(int v[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < v[i]; j++){
            putchar(200);
        }
        putchar('\n');
    }
}

int main(void){
    int a[4] = {3, 5, 1, 7};
    int b[3] = {4, 2, 6};
    barras(a, 4);
    getchar();
    barras(b, 3);
    return 0;
}
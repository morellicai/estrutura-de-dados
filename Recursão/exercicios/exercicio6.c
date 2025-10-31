#include <stdio.h>

void cr(int n) {
  if (n == 0)
    return;

  printf("%d\n", n);
  cr(n - 1);
}

int main(void) {
  int n;
  printf("Contagem regressiva. De qual número quer contar?\nNúmero = ");
  scanf("%d", &n);
  cr(n);
  return 0;
}

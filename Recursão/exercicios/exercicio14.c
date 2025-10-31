#include <stdio.h>

int sd(int n) {
  if (n == 0)
    return 0; // Caso base

  return (n % 10) + sd(n / 10); // Passo recursivo
}

int main(void) {
  int n;
  printf("Digite um número: ");
  scanf("%d", &n);

  printf("A soma dos dígitos de %d é %d\n", n, sd(n));

  return 0;
}

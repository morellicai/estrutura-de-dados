#include <stdio.h>

int h(int n) {
  if (n == 1)
    return 1;
  return 2 * h(n - 1) + 1;
}

void hanoi(int n, char origem, char auxiliar, char destino) {
  if (n == 1) {
    printf("Mova o disco 1 de %c para %c\n", origem, destino);
    return;
  }
  hanoi(n - 1, origem, destino, auxiliar);
  printf("Mova o disco %d de %c para %c\n", n, origem, destino);
  hanoi(n - 1, auxiliar, origem, destino);
}

int main() {
  int n;
  printf("Quantos discos? ");
  scanf("%d", &n);

  printf("\nNúmero mínimo de movimentos: %d\n\n", h(n));
  hanoi(n, 'A', 'B', 'C');

  return 0;
}

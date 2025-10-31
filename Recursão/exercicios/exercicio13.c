#include <stdio.h>

int quadrado(int num) {
  if (num < 1) {
    return 0;
  }

  int n = quadrado(num - 1);
  int count = 2 * num - 1;

  return n + count;
}

int main() {
  int num;
  printf("Número? ");
  scanf("%d", &num);
  printf("%d^2 = %d", num, quadrado(num));
  return 0;
}

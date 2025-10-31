#include <stdio.h>

int quoc(int m, int n) {
  if (m < n) {
    return 0;
  }

  return 1 + quoc(m - n, n);
}

int main(void) {
  int n1, n2;

  while (1) {
    printf("Qual o Dividendo? ");
    scanf("%d", &n1);
    printf("Qual o Divisor? ");
    scanf("%d", &n2);

    if (n1 < 1 || n2 < 1) {
      printf("Divisão não altorisada");
    } else {
      printf("%d / %d = %d", n1, n2, quoc(n1, n2));
      break;
    }
  }

  return 0;
}

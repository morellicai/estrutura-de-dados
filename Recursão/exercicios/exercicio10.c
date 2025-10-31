#include <stdio.h>

int prod(int m, int n) {
  if (n == 0) {
    return 0;
  }

  return m + prod(m, n - 1);
}

int main(void) {
  int num1;
  int num2;
  printf("Numeros a ser multiplicados?\n");
  while (1) {
    scanf("%d %d", &num1, &num2);
    if (num1 < 0 || num2 < 0) {
      printf("Só pode ser numero positivo!\n");
    } else {
      printf("%d * %d = %d", num1, num2, prod(num1, num2));
      break;
    }
  }
  return 0;
}

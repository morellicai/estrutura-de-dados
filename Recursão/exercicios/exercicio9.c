#include <stdio.h>

int par(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return par(n - 2);
    if (n == 1) {
      return 1;
    }
    return 0;
  }
}

int main(void) {
  int n;
  printf("Digite um número: ");
  scanf("%d", &n);

  if (par(n) == 0) {
    printf("Digito é par");
  } else {
    printf("Digito é impar");
  }
  return 0;
}

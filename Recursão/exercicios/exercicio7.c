#include <stdio.h>

void binario(int n) {
  if (n < 2)
    printf("%d", n);
  else {
    binario(n / 2);
    printf("%d", n % 2);
  }
}

int main() {
  int n;
  printf("Qual o número? ");
  scanf("%d", &n);
  binario(n);
  return 0;
}

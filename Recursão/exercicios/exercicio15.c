#include <stdio.h>

int qd(int n) {
  if (n < 2)
    return 1;

  return 1 + qd(n / 2);
}

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
  printf("A quantidade de digitos binários para o %d é: %d\n", n, qd(n));
  printf("Pois %d em binário é: ", n);
  binario(n);
  return 0;
}

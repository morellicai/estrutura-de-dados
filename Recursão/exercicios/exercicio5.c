#include <stdio.h>

void cp(int n) {
  if (n == 0)
    return;

  cp(n - 1);
  printf("%d\n", n);
}

int main() {
  int n;
  printf("Contagem progressiva. diga o número para contagem\nnúmero = ");
  scanf("%d", &n);
  cp(n);
  return 0;
}

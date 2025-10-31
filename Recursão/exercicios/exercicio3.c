#include <stdio.h>

int termial(int n) {
  if (n == 0)
    return 0;

  return termial(n - 1) + n;
}

int main() {
  int n;

  printf("Número? ");
  scanf("%d", &n);
  printf("Termial = %d", termial(n));

  return 0;
}

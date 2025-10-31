#include <stdio.h>

float pot(float x, int n) {
  if (n == 0) {
    return 1;
  }

  return x * pot(x, n - 1);
}

int main(void) {
  float x;
  int n;

  printf("Base e expoente? ");
  scanf("%f %d", &x, &n);
  printf("%.1f^%d = %.1f", x, n, pot(x, n));
  return 0;
}

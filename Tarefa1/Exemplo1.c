#include <math.h>
#include <stdio.h>

int main(void) {
  float p, a, i;
  printf("Peso e Altura? ");
  scanf("%f %f", &p, &a);
  i = p / pow(a, 2);
  printf("IMC = %.2f\n", i);
  return 0;
}

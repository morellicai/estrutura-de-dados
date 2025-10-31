#include <math.h>
#include <stdio.h>

int main(void) {
  float p, a, i;
  printf("Peso e Altura? ");
  scanf("%f %f", &p, &a);
  i = p / pow(a, 2);
  printf("IMC = %.2f\n", i);
  if (i < 18.5) {
    puts("Está Magra");
  } else if (i > 30.0) {
    puts("Está obeso");
  } else {
    puts("Está em forma");
  }
  return 0;
}

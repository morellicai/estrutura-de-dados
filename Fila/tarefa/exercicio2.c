#include "fila.h"
#include <stdio.h>

int main(void) {
  Fila F = fila(5);
  for (int i = 0; i <= 3; i++) {
    enfileira('A' + i, F);
  }
  while (!vaziaf(F)) {
    printf("%c\n", desenfileira(F));
  }
  destroif(&F);
  return 0;
}

#include "listaEncadeada.h"
#include <stdio.h>

void anexa(Lista *A, Lista B) {
  if (!B)
    return;

  while (*A)
    A = &(*A)->prox;
  *A = B;
}

int main(void) {
  Lista H = no(4, no(2, NULL));
  Lista I = no(3, no(1, no(5, NULL)));

  printf("H = ");
  exibe2(H);
  printf("\nI = ");
  exibe2(I);
  printf("\nPressione enter");

  getchar();

  anexa(&H, I);
  printf("H = ");
  exibe2(H);
  printf("\nI = ");
  exibe2(I);

  return 0;
}

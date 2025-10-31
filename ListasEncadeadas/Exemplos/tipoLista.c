#include "listaEncadeada.h"
#include <stdlib.h>

Lista aleatoria(int n, int m) {
  Lista L = NULL;
  while (n > 0) {
    L = no(rand() % m, L);
    n--;
  }
  return L;
}

void anexa(Lista *A, Lista B) {
  if (!B)
    return;
  while (*A)
    A = &(*A)->prox;
  *A = B;
}

int main(void) {
  Lista I = no(3, no(1, no(5, NULL)));
  return 0;
}

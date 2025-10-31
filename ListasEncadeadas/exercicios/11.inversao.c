#include "listaEncadeada.h"
#include <stdio.h>

Lista inversa(Lista L) {
  Lista R = NULL;

  while (L != NULL) {
    R = no(L->item, R);
    L = L->prox;
  }
  return R;
}

int main(void) {
  Lista A = no(1, no(2, no(3, no(4, NULL))));
  exibe2(A);
  printf("\n");
  Lista B = inversa(A);
  exibe2(B);

  destroi(&B);
  destroi(&A);
  return 0;
}

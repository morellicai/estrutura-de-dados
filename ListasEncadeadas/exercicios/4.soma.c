#include "listaEncadeada.h"
#include <stdio.h>

int soma(Lista L) {
  int result = 0;

  while (L != NULL) {
    result = result + L->item;
    L = L->prox;
  }
  return result;
}

int main(void) {
  Lista I = no(3, no(1, no(5, NULL)));
  exibe2(I);
  if (soma(I) == 0) {
    printf("lista vazia");
    return 0;
  }
  printf("\nResultado da soma dos itens da lista é: %d\n", soma(I));
}

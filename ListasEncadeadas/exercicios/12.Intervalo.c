#include "listaEncadeada.h"
#include <stdio.h>

Lista intervalo(int part, int final) {
  Lista L = NULL;

  if (part > final) {
    return L;
  }

  for (int i = final; i >= part; i--) {
    L = no(i, L);
  }

  return L;
}

int main(void) {
  int part, final;

  printf("Defina o intervalo da contagem.\n");
  scanf("%d %d", &part, &final);

  Lista L = intervalo(part, final);

  printf("A contagem: ");
  exibe2(L);

  destroi(&L);
  return 0;
}

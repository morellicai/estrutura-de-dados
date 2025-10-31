#include "listaEncadeada.h"

Lista intervalo(int n) {
  Lista L = NULL;
  for (int i = n; i > 0; i--) {
    L = no(i, L);
  }

  return L;
}

int main(void) {
  int n;
  printf("Até quanto devo contar? ");
  scanf("%d", &n);

  printf("Contando... \n");
  exibe(intervalo(n));
  return 0;
}

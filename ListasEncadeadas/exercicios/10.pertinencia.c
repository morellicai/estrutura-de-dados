#include "listaEncadeada.h"
#include <stdio.h>
#include <time.h>

int pertence(int x, Lista L) {
  if (L == NULL) {
    return 0;
  }

  while (L != NULL) {
    if (x == L->item) {
      return 1;
    }
    L = L->prox;
  }
  return 0;
}

int main(void) {
  srand(time(NULL));
  Lista A = aleatoria(10, 100);
  int num;

  printf("Qual o número? ");
  scanf("%d", &num);

  int pert = pertence(num, A);

  exibe2(A);
  if (pert == 1) {
    printf("\nNúmero %d pertence à lista.", num);
    return 0;
  }
  printf("\nNúmero %d não pertence a lista", num);
  return 0;
}

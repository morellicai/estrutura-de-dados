#include "listaEncadeada.h"
#include <stdio.h>
#include <time.h>

int enesimo(Lista L, int n) {
  if (L == NULL)
    return -1; // ou valor sentinela
  if (n == 1)
    return L->item;
  return enesimo(L->prox, n - 1);
}

int main(void) {
  srand(time(NULL));
  Lista L = aleatoria(10, 20);

  int num;

  printf("Qual a posição deseja checar? ");
  scanf("%d", &num);

  int nesimo = enesimo(L, num);

  printf("O valor na posição %d é %d\n", num, nesimo);
  exibe2(L);

  destroi(&L);
  return 0;
}

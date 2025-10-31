#include "listaEncadeada.h"
#include <stdio.h>
#include <time.h>

void divide(Lista L, Lista *metade1, Lista *metade2) {
  if (L == NULL || L->prox == NULL) {
    *metade1 = L;
    *metade2 = NULL;
    return;
  }

  Lista lento = L;
  Lista rapido = L->prox;

  while (rapido != NULL) {
    rapido = rapido->prox;
    if (rapido != NULL) {
      lento = lento->prox;
      rapido = rapido->prox;
    }
  }

  *metade1 = L;
  *metade2 = lento->prox;
  lento->prox = NULL;
}

Lista intercalar(Lista a, Lista b) {
  if (a == NULL)
    return b;
  if (b == NULL)
    return a;

  Lista resultado = NULL;

  if (a->item <= b->item) {
    resultado = a;
    resultado->prox = intercalar(a->prox, b);
  } else {
    resultado = b;
    resultado->prox = intercalar(a, b->prox);
  }

  return resultado;
}

Lista ordenar(Lista L) {
  if (L == NULL || L->prox == NULL)
    return L;

  Lista metade1, metade2;

  divide(L, &metade1, &metade2);

  metade1 = ordenar(metade1);
  metade2 = ordenar(metade2);

  return intercalar(metade1, metade2);
}

int main() {
  srand(time(NULL));
  Lista L = aleatoria(10, 100);

  printf("A lista atual é: ");
  exibe2(L);

  printf("\nA lista ordenada: ");
  Lista A = ordenar(L);
  exibe2(A);

  destroi(&L);
  return 0;
}

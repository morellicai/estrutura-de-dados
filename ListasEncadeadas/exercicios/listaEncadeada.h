#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct no {
  Item item;
  struct no *prox;
} *Lista;

Lista no(Item x, Lista p) {
  Lista n = malloc(sizeof(struct no));
  n->item = x;
  n->prox = p;
  return n;
}

void exibe(Lista L) {
  while (L != NULL) {
    printf("%d\n", L->item);
    L = L->prox;
  }
}

void exibe2(Lista L) {
  printf("[");

  if (L == NULL) {
    printf("]");
    return;
  }

  while (L != NULL) {
    printf("%d", L->item);
    if (L->prox != NULL) {
      printf(",");
    }
    L = L->prox;
  }

  printf("]");
}

int tamanho(Lista L) {
  int t = 0;
  while (L) {
    t++;
    L = L->prox;
  }
  return t;
}

Lista aleatoria(int n, int m) {
  Lista L = NULL;
  while (n > 0) {
    L = no(rand() % m, L);
    n--;
  }

  return L;
}

void destroi(Lista *L) {
  while (*L) {
    Lista n = *L;
    *L = n->prox;
    free(n);
  }
}

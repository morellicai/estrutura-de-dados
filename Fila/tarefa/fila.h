// fila.h - implementacao dinamica sequencial de fila
#include <stdio.h>
#include <stdlib.h>

#define avanca(i) (i = (i + 1) % F->max)

typedef int Itemf;

typedef struct fila {
  int max;
  int total;
  int inicio;
  int final;
  Itemf *item;
} *Fila;

Fila fila(int m) {
  Fila F = malloc(sizeof(struct fila));
  F->max = m;                          // Tamanho maximo da fila
  F->total = 0;                        // Numero de elementos na fila
  F->inicio = 0;                       // Indice do elemento mais antigo
  F->final = 0;                        // Indice do proximo elemento livre
  F->item = malloc(m * sizeof(Itemf)); // Vetor de itens
  return F;
}

int vaziaf(Fila F) { return (F->total == 0); }

int cheiaf(Fila F) { return (F->total == F->max); }

void enfileira(Itemf x, Fila F) {
  if (cheiaf(F)) {
    puts("fila cheia!");
    abort();
  }
  F->item[F->final] = x;
  avanca(F->final);
  F->total++;
}

Itemf desenfileira(Fila F) {
  if (vaziaf(F)) {
    puts("fila vazia!");
    abort();
  }
  Itemf x = F->item[F->inicio];
  avanca(F->inicio);
  F->total--;
  return x;
}

void destroif(Fila *G) {
  free((*G)->item);
  free(*G);
  *G = NULL;
}

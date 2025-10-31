#include "conio.h"
#include "fila.h"
#include <stdio.h>

#define dim 9
#define cor(i, j) (i >= 0 && i < dim && j >= 0 && j < dim ? I[i][j] : -1)
#define par(i, j) ((i) * 100 + (j))
#define lin(p) ((p) / 100)
#define col(p) ((p) % 100)

int I[dim][dim] = {{0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0},
                   {0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 1, 1, 1, 1, 0, 0},
                   {0, 1, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 2, 0, 0, 0, 2, 0, 0},
                   {0, 0, 2, 0, 0, 0, 2, 0, 0}, {0, 0, 2, 2, 2, 2, 2, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0}};

void inicia(int I[dim][dim], char *s) {
  FILE *a = fopen(s, "r");
  if (!a) {
    puts("arquivo não encontrado");
    abort();
  }
  for (int i = 0; i < dim; i++)
    for (int j = 0; j < dim; j++)
      fscanf(a, "%d", &I[i][j]);
  fclose(a);
}

void exiba(int I[dim][dim]) {
  for (int i = -1; i < dim; i++) {
    textcolor(8);
    for (int j = -1; j < dim; j++)
      if (i < 0 && j < 0)
        printf("  ");
      else if (i < 0)
        printf("%2d", j);
      else if (j < 0)
        printf("\n%2d", i);
      else {
        textcolor(I[i][j]);
        printf("%c%c", 35, 35);
      }
  }
  textcolor(8);
}

void colorir(int I[dim][dim], int i, int j, int n) {
  int a = I[i][j];

  if (a == n)
    return;

  Fila F = fila(dim * dim);
  I[i][j] = n;
  enfileira(par(i, j), F);

  while (!vaziaf(F)) {
    int p = desenfileira(F);
    i = lin(p);
    j = col(p);

    if (cor(i - 1, j) == a) {
      I[i - 1][j] = n;
      enfileira(par(i - 1, j), F);
    }
    if (cor(i, j + 1) == a) {
      I[i][j + 1] = n;
      enfileira(par(i, j + 1), F);
    }
    if (cor(i + 1, j) == a) {
      I[i + 1][j] = n;
      enfileira(par(i + 1, j), F);
    }
    if (cor(i, j - 1) == a) {
      I[i][j - 1] = n;
      enfileira(par(i, j - 1), F);
    }
  }

  destroif(&F);
}

int main(void) {
  int I[dim][dim];

  inicia(I, "imagem.txt");

  printf("Imagem original:\n");
  exiba(I);

  int i, j, n;
  printf("\nPosição (linha, coluna): ");
  scanf("%d %d", &i, &j);
  printf("Nova cor: ");
  scanf("%d", &n);

  colorir(I, i, j, n);

  printf("\nImagem colorida:\n");
  exiba(I);

  return 0;
}

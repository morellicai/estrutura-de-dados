#include "pilha.h"
#include <stdio.h>

int main(void) {
  Pilha P = pilha(5);
  char s[11];

  for (int i = 1; i <= 3; i++) {
    printf("? ");
    fgets(s, 11, stdin);
    empilha(s, P);
  }

  while (!vaziap(P)) {
    puts(desempilha(P));
  }
  return 0;
}

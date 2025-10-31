#include <stdio.h>
#include <string.h>

char *inv(char s[], int p, int u) {
  if (p >= u) {
    return s;
  }

  char temp = s[p];
  s[p] = s[u];
  s[u] = temp;

  return inv(s, p + 1, u - 1);
}

int main() {
  char s[100];
  printf("digite uma string: ");
  scanf("%s", s);

  int tamanho = strlen(s);
  printf("string invertida: %s\n", inv(s, 0, tamanho - 1));

  return 0;
}

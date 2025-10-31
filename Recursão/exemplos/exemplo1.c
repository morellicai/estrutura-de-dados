#include <stdio.h>

int fat(int x) {
  if (x == 0) {
    return 1;
  }
  return x * fat(x - 1);
}

int main(void) {
  int n;
  printf("Numero? ");
  scanf("%d", &n);
  printf("Fat = %d\n", fat(n));
  return 0;
}

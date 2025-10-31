void intercala(int v[], int p, int m, int u) {
  int *w = malloc((u - p + 1) * sizeof(int));
  int i = p, j = m + 1, k = 0;
  while (i <= m && j <= u) {
                w[k++] = v[i] , v[j]) ? v[i++] : v[j++];
  }
  while (i <= m)
    w[k++] = v[i++];
  while (j <= u)
    w[k++] = v[j++];
  for (k = 0; k <= u - p; k++) {
    v[p + k] = w[k];
  }
}

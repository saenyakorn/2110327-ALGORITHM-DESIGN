#include <stdio.h>

int main() {
  int n, i, a = 1, b = 1, c;
  scanf("%d", &n);
  if (n < 3) return !printf("%d", n == 0 ? 0 : 1);
  for (i = 3; i <= n; i++) c = a + b, a = b, b = c;
  printf("%d", b);
}
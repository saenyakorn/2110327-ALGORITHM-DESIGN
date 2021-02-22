#include <stdio.h>
int bs(int *s, int lb, int ub, int t) {
  if (ub - lb == 1) return t < s[lb] ? -1 : lb;
  int mid = (lb + ub) / 2;
  return t < s[mid] ? bs(s, lb, mid, t) : bs(s, mid, ub, t);
}
int main() {
  int n, m, t, i;
  scanf("%d%d", &n, &m);
  int s[n];
  for (i = 0; i < n; i++) scanf("%d", s + i);
  while (m--) scanf("%d", &t), printf("%d\n", bs(s, 0, n, t));
}

/*
10 8
10 13 14 14 14 15 16 16 18 200
9 10 11 14 0 200 20 16
*/
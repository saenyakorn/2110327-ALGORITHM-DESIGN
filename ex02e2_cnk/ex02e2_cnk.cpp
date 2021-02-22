#include <stdio.h>
int dp[31][31] = {0};
int C(int n, int k) {
  if (dp[n][k] != 0) return dp[n][k];
  return dp[n][k] = n == k || k == 0 ? 1 : C(n - 1, k - 1) + C(n - 1, k);
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  printf("%d", C(n, k));
}

/*
10 3
10 10
30 15
*/
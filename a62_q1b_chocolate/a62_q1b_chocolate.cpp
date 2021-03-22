#include <cstdio>

int s[11] = {0};
int dp[10002] = {0};

int slice(int n, int k) {
  if (dp[n] != 0) return dp[n];
  if (n == 0) return dp[n] = 1;
  for (int i = 1; i <= k; i++) {
    if (n - s[i] >= 0) dp[n] = (dp[n] + slice(n - s[i], k)) % 1000003;
  }
  return dp[n];
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; i++) scanf("%d", s + i);
  printf("%d\n", slice(n, k));
}

/*
4 2
1 3

10 2
1 2

10 5
1 2 4 6 8

999 5
1 2 4 50 999
*/
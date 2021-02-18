#include <cstdio>

using namespace std;

int dp[501][501];

int divide(int n, int k) {
  if (dp[n][k] != -1) return dp[n][k];
  if (k == 1) return dp[n][k] = 1;
  if (n < k) return dp[n][k] = 0;
  int sum = (k * divide(n - 1, k) + divide(n - 1, k - 1)) % 1997;
  return dp[n][k] = sum;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < 501; i++)
    for (int j = 0; j < 501; j++) dp[i][j] = -1;
  printf("%d\n", divide(n, k));
}

/*
3 2

4 1 

4 2 

4 3 

7 3

499 23
*/
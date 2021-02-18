#include <cstdio>

using namespace std;

int M;
int dp[31][31][31];

int barcode(int n, int m, int k) {
  if (dp[n][m][k] != -1) return dp[n][m][k];
  if (m < 0) return 0;
  if (n == 1) return dp[n][m][k] = k == 0 ? 1 : 0;
  dp[n][m][k] = barcode(n - 1, m - 1, k);
  if (k > 0) dp[n][m][k] += barcode(n - 1, M - 1, k - 1);
  return dp[n][m][k];
}

int main() {
  int n, k;

  scanf("%d%d%d", &n, &M, &k);
  for (int i = 0; i < 31; i++)
    for (int j = 0; j < 31; j++)
      for (int k = 0; k < 31; k++)
        dp[i][j][k] = -1;

  printf("%d\n", barcode(n, M - 1, k));
}

/*
4 3 1

5 2 2

7 9 4
*/
#include <algorithm>
#include <climits>
#include <cstdio>

using namespace std;

int dp[21][10002] = {0};
int p[21] = {0};

int coin(int n, int m) {
  if (dp[n][m] != 0) return dp[n][m];
  if (n == 0) return dp[n][m] = INT_MAX;
  if (m == 0) return 0;
  if (m >= p[n])
    return dp[n][m] = min(1 + coin(n, m - p[n]), coin(n - 1, m));
  return dp[n][m] = coin(n - 1, m);
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", p + i);
  sort(p + 1, p + n + 1);
  printf("%d\n", coin(n, m));
}

/*
4 28
10 5 2 1

3 13
5 4 1
*/
#include <algorithm>
#include <cstdio>

using namespace std;

int dp[501][501] = {0}, t[501][501];

int max3(int a, int b, int c) {
  return max(a, max(b, c));
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &t[i][j]);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = max3(t[i][j] + dp[i - 1][j], t[i][j] + dp[i][j - 1], (i == 1 || j == 1 ? 1 : 2) * t[i][j] + dp[i - 1][j - 1]);
    }
  }
  printf("%d", dp[n][m]);
}

/*
1 5
1 2 3 4 5

3 3
1 1 10
1 7 10
1 10 20

3 3
1 1 10
1 7 10
1 9 7
*/
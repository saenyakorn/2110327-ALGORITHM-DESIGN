#include <algorithm>
#include <climits>
#include <cstdio>

using namespace std;

int main() {
  int n, k, i, j, t, dp[10001][2];
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++) {
    dp[i][0] = dp[i][1] = INT_MAX;
    scanf("%d", &t);
    if (i == 0) {
      dp[i][1] = t;
      continue;
    }
    if (i <= k)
      dp[i][1] = t;
    else
      for (j = max(0, i - 2 * k - 1); j < i; j++) dp[i][1] = min(dp[i][1], t + dp[j][1]);
    for (j = max(0, i - k); j < i; j++) dp[i][0] = min(dp[i][0], dp[j][1]);
  }
  printf("%d", min(dp[n - 1][0], dp[n - 1][1]));
}

/*
5 1
1 99 1 99 1

5 1
99 1 99 1 99

7 3
1 2 3 4 3 2 1
*/
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> v(n), dp(n, 0);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);

  for (int i = 0; i < n; i++) {
    if (i == 0)
      dp[i] = v[i];
    else {
      dp[i] = i >= 3 ? max(v[i] + dp[i - 2], v[i] + dp[i - 3]) : v[i] + dp[i - 2];
      dp[i] = max(dp[i], dp[i - 1]);
    }
  }
  printf("%d\n", dp[n - 1]);
}

/*
3
3 4 2

10
48 1 3 95 2 1 3 44 22 2
*/
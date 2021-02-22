#include <algorithm>
#include <climits>
#include <cstdio>

using namespace std;

int dp[101][101] = {0};

int mul(int *s, int lb, int ub) {
  if (dp[lb][ub] != 0) return dp[lb][ub];
  if (ub - lb == 0) return dp[lb][ub] = 0;
  int mn = INT_MAX;
  for (int i = lb; i < ub; i++) {
    int l = mul(s, lb, i), r = mul(s, i + 1, ub);
    int op = s[lb] * s[i + 1] * s[ub + 1];
    mn = min(mn, op + l + r);
  }
  return dp[lb][ub] = mn;
}

int main() {
  int n;
  scanf("%d", &n);
  int s[n + 1], dp[n + 1];
  for (int i = 0; i <= n; i++) scanf("%d", s + i);
  printf("%d\n", mul(s, 0, n - 1));
}

/*
3
10 10 10 1

7
92 32 7 3 29 74 57 93
*/
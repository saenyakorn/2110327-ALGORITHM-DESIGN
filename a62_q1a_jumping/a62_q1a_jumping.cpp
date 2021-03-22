#include <algorithm>
#include <cstdio>

int dp[1000002] = {0};

int max3(int a, int b, int c) {
  return std::max(a, std::max(b, c));
}

int main() {
  int n, t;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t);
    if (i == 1)
      dp[i] = t;
    else
      dp[i] = t + max3(dp[std::max(i - 1, 1)], dp[std::max(i - 2, 1)], dp[std::max(i - 3, 1)]);
  }
  printf("\n%d", dp[n]);
}

/*
3
1 1 1

3
1 -1 1

7
1 -1 -1 -1 -1 -1 1

10
1 2 3 4 5 6 7 8 9 10

10
-1 -2 -3 -1 -5 -7 6 8 -9 3

10
-1 -2 -2 -1 -4 -2 -3 -5 -4 -1
*/
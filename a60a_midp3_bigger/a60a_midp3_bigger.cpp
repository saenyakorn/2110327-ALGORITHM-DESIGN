#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int billboard(vector<int> &arr, int n, vector<int> &dp) {
  if (dp[n] != -1) return dp[n];
  if (n < 3) {
    int mx = -1;
    for (int i = 0; i <= n; i++) mx = max(mx, arr[i]);
    return dp[n] = mx;
  }
  int mx = billboard(arr, n - 1, dp);
  if (n >= 3) mx = max(mx, arr[n] + billboard(arr, n - 3, dp));
  return dp[n] = mx;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> arr(n), dp(n, -1);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  printf("%d\n", billboard(arr, n - 1, dp));
}

/*
5
1 1 1 1 1

3
3 4 2

10
48 1 3 95 2 1 3 44 22 2
*/
#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

vector<int> s(3);
int dp[4001] = {0};
int forbidden[4001] = {0};

int cut(int n) {
  if (dp[n] != 0) return dp[n];
  if (n == 0) return dp[n] = 0;
  int mx = 0, p = 1;
  for (int i = 0; i < s.size(); i++) {
    if (n - s[i] >= 0 && !forbidden[n - s[i]])
      mx = max(mx, 1 + cut(n - s[i])), p &= forbidden[n - s[i]];
  }
  forbidden[n] = p;
  if (!p) dp[n] = mx;
  return dp[n];
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 3; i++) scanf("%d", &s[i]);
  sort(s.begin(), s.end());
  vector<int>::iterator ip = unique(s.begin(), s.end());
  s.resize(distance(s.begin(), ip));
  for (int i = 1; i < s[0]; i++) forbidden[i] = 1;
  printf("%d\n", cut(n));
}

/*
10 2 3 4

9 2 3 4

5 5 3 2

7 5 5 2 

10 5 4 3 

21 5 6 7
*/
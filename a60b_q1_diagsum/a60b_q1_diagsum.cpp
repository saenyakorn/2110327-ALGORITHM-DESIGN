#include <algorithm>
#include <climits>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> V;

int find_max(V &v, int l) {
  int mx = INT_MIN, sum = 0;
  for (int i = 0; i < l; i++) {
    sum += v[i];
    if (mx < sum) mx = sum;
    if (sum < 0) sum = 0;
  }
  return mx;
}

int main() {
  int n;
  scanf("%d", &n);

  int t[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &t[i][j]);

  int mx = INT_MIN;
  V a(n, INT_MIN), b(n, INT_MIN);
  for (int i = 0; i < n; i++) {
    int p = 0;
    for (p = 0; p < n && i + p < n; p++) {
      a[p] = t[i + p][p];
      b[p] = t[p][i + p];
    }
    if (i == 0)
      mx = find_max(a, p);
    else
      mx = max(mx, max(find_max(a, p), find_max(b, p)));
  }
  printf("%d\n", mx);
}

/*
4
1 2 3 4
-2 -5 2 -5
6 3 -7 1
3 -2 7 -9

2
1 2
3 4

4
-1 -1 -1 -1
-1 -1 -1 -1
-1 -1 -1 -1
-1 -1 -1 -1
*/
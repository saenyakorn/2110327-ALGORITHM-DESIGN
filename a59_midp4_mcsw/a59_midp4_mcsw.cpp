#include <algorithm>
#include <climits>
#include <cstdio>
#include <vector>

using namespace std;

int mcs(vector<int> &v, int w) {
  int mx = 0, mx_far = INT_MIN, lb = 0, ub = 0, s = 0, e = 0;
  for (int i = 0; i < v.size(); i++) {
    if (e - s >= w) {
      i = s = e = s + 1, mx = 0;
      continue;
    }
    mx += v[i];
    if (mx_far < mx)
      mx_far = mx, lb = s, ub = i;
    if (mx <= 0)
      mx = 0, s = i + 1, e = i + 1;
    else
      e += 1;
    //printf("mx_far=%d mx=%d s=%d i=%d lb=%d ub=%d\n", mx_far, mx, s, i, lb, ub);
  }
  //printf("subarray: (%d,%d)\n", lb, ub);
  return mx_far;
}

int main() {
  int n, w;
  scanf("%d%d", &n, &w);
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  printf("%d\n", mcs(v, w));
}

/*
5 3
-10 -2 -3 -4 -5

10 4 
1 4 2 -3 5 -7 3 9 2 -7
*/
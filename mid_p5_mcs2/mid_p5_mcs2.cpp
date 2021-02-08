#include <climits>
#include <cstdio>
#include <vector>

using namespace std;

int mcs(vector<int>& v) {
  int sum = 0, mx = INT_MIN;
  for (int i = 0; i < v.size(); i++) {
    sum += v[i];
    if (mx < sum) mx = sum;
    if (sum < 0) sum = 0;
  }
  return mx;
}

int maxCir(vector<int>& v) {
  int sum = 0, mx = mcs(v);
  for (int i = 0; i < v.size(); i++) sum += v[i], v[i] = -v[i];
  int mn = mcs(v);
  if (sum == -mn) return mx;
  return max(mx, sum + mn);
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> v(n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  printf("%d\n", maxCir(v));
}

/*
4
1 -2 -3 1

15
1 2 -1 5 3 -8 -2 4 3 -4 -5 7 -1 -2 4

8
-1 -2 -2 -2 -2 -2 -2 -1
*/
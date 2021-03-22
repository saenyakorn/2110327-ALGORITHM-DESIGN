#include <cstdio>
#include <vector>

using namespace std;

int climb(const vector<int> &v, int k) {
  int day = 1, prev = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] - prev > k) {
      day += 1, prev = v[i - 1];
      if (v[i] - v[i - 1] > k) return v.back();
    }
  }
  return day;
}

int findK(const vector<int> &v, int d, int lb, int ub) {
  int mid = (lb + ub) / 2;
  if (ub == lb) return lb;
  if (climb(v, mid) <= d)
    return findK(v, d, lb, mid);
  else
    return findK(v, d, mid + 1, ub);
}

int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  int sum = 0;
  int diff = 0;
  vector<int> v(n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]), sum += v[i];
  int k = findK(v, d, 1, v.back() + 1);
  int x = climb(v, k);
  printf("%d %d\n", k, x);
}

/*
9 3
10 30 50 70 90 110 120 170 180

6 4
30 60 90 120 150 180
*/
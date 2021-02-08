#include <cstdio>
#include <vector>

using namespace std;

vector<int> hadamard(vector<int> &v, int lb, int ub, int n) {
  if (n == 1) return vector<int>(1, v[lb]);
  int mid = (lb + ub) / 2;
  vector<int> tmp(n);
  vector<int> hl = hadamard(v, lb, mid, n / 2), hr = hadamard(v, mid, ub, n / 2);
  for (int i = 0; i < n / 2; i++)
    tmp[i] = hl[i] + hr[i];
  for (int i = n / 2; i < n; i++) {
    tmp[i] = hl[i - n / 2] - hr[i - n / 2];
  }
  return tmp;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> v(n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  vector<int> r = hadamard(v, 0, n, n);
  for (int i = 0; i < r.size(); i++) printf("%d ", r[i]);
}

/*
1
10

2
10 20

4
1 2 4 8
*/
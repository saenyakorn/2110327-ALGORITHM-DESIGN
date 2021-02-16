#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> V;

void multiple(V &t, const V &m, int k) {
  int a = (t[0] * m[0]) % k + (t[1] * m[2]) % k;
  int b = (t[0] * m[1]) % k + (t[1] * m[3]) % k;
  int c = (t[2] * m[0]) % k + (t[3] * m[2]) % k;
  int d = (t[2] * m[1]) % k + (t[3] * m[3]) % k;
  t[0] = a % k, t[1] = b % k, t[2] = c % k, t[3] = d % k;
}

V power(const V &m, int n, int k) {
  if (n == 1) return m;
  V r = power(m, n / 2, k);
  multiple(r, r, k);
  if (n % 2) multiple(r, m, k);
  return r;
}

int main() {
  int n, k, i = 0, j = 0;
  scanf("%d%d", &n, &k);
  V m(4);
  while (i < 4) scanf("%d", &m[i++]);
  V p = power(m, n, k);
  while (j < 4) printf("%d ", p[j++]);
}

/*
2 1000
1 2 3 4

2 10
1 2 3 4

5 10000
1 2 3 4

5 10
1 2 3 4

999888777 4726
3 8 7 2
*/
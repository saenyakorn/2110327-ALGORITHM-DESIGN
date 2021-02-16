#include <cmath>
#include <cstdio>

using namespace std;

int one(int n, int p) {
  if (n == 1) return p;
  int pow = (int)(log2(n));
  int pos = (1 << pow) - 1;
  if (p <= pos) return one(n / 2, p);
  if (p == pos + 1) return n / 2 + n % 2;
  return n / 2 + n % 2 + one(n / 2, p - pos - 1);
}

int main() {
  int n, l, r;
  scanf("%d%d%d", &n, &l, &r);
  printf("%d\n", one(n, r) - one(n, l - 1));
}

/*
9 2 8

7 2 5

10 3 10
*/
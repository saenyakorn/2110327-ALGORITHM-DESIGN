#include <cstdio>

using namespace std;

int powermod(int X, int N, int K) {
  if (N >= 1) {
    int r = powermod(X, N / 2, K);
    r = (r * r) % K;
    if (N % 2) r = (r * X) % K;
    return r;
  }
  return 1;
}

int main() {
  int X, N, K;
  scanf("%d%d%d", &X, &N, &K);
  printf("%d", powermod(X, N, K));
}

/*
2 5 100

2 5 10

123 4727 153
*/
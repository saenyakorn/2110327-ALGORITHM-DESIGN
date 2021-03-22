#include <algorithm>
#include <climits>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

typedef vector<int> V;

int p, k;
long long a, b;

int hero(V& av, int lb, int ub) {
  V::iterator lo = lower_bound(av.begin(), av.end(), lb);
  V::iterator up = upper_bound(av.begin(), av.end(), ub);
  return up - lo;
}

long long thanos(V& av, int lb, int ub, int p) {
  int mid = (lb + ub) / 2, sum = INT_MAX;
  if (ub - lb >= 1) {
    int h = hero(av, lb, ub);
    if (h == 0) return a;
    long long L = thanos(av, lb, mid, p - 1);
    long long R = thanos(av, mid + 1, ub, p - 1);
    long long sum = L + R;
    sum = min(sum, b * h * (ub - lb + 1));
    return sum;
  } else {
    int h = hero(av, lb, ub);
    return h == 0 ? a : b * h;
  }
}

int main() {
  scanf("%d%d%lld%lld", &p, &k, &a, &b);
  V av(k);
  for (int i = 0; i < k; i++) scanf("%d", &av[i]);
  sort(av.begin(), av.end());
  printf("%lld", thanos(av, 1, 1 << p, p));
}

/*
6 7 1 1
1 2 4 5 31 50 60  

2 2 1 2
1 3

3 2 1 2
1 7

2 1 10 1
1
*/
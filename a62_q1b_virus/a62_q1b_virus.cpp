#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int base[] = {0, 1};

bool check(vector<int>& v, int lb, int ub) {
  if (ub - lb > 2) {
    int mid = (lb + ub) / 2;
    bool L, REV, R;
    L = check(v, lb, mid);
    reverse(v.begin() + lb, v.begin() + mid);
    REV = check(v, lb, mid);
    reverse(v.begin() + lb, v.begin() + mid);
    R = check(v, mid, ub);
    return (L || REV) && R;
  }
  return v[lb] == base[0] && v[lb + 1] == base[1];
}

int main() {
  int N, K;
  scanf("%d%d", &N, &K);
  K = 1 << K;
  vector<int> v(K);
  while (N--) {
    for (int i = 0; i < K; i++) scanf("%d", &v[i]);
    printf("%s\n", check(v, 0, K) ? "yes" : "no");
  }
}

// 0 1 1 0 0 1 0 1

/*
4 1
0 1
1 0
0 0
1 1

4 2
1 1 0 0
1 0 0 1
0 0 0 0

5 3
1 0 0 1 0 1 0 1 
1 0 1 0 1 0 0 1 
1 0 1 1 1 0 0 0

5 4
0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 
0 1 0 1 0 1 0 1 0 1 0 1 1 0 0 1 
0 1 0 1 0 1 0 1 1 0 0 1 0 1 0 1 
0 1 0 1 0 1 0 1 1 0 0 1 1 0 0 1 
0 1 0 1 0 1 0 1 1 0 1 0 0 1 0 1
*/
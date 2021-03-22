#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int cnt[4] = {0};

int main() {
  int n;
  scanf("%d", &n);
  vector<int> v(n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]), cnt[v[i]] += 1;
  int t1 = 0, t3 = 0, i1 = 0, i3 = n - 1, d = 0;
  while (v[i1] == 1) i1++, cnt[1]--;
  while (v[i3] == 3) i3--, cnt[3]--;
  int c1 = 0, c3 = 0;
  for (int i = i1, a1 = cnt[1]; i < i1 + a1; i++) {
    if (v[i] == 3) c3 += 1;
    if (v[i] == 1) cnt[1]--;
  }
  for (int i = i3, a3 = cnt[3]; i > i3 - a3; i--) {
    if (v[i] == 1) c1 += 1;
    if (v[i] == 3) cnt[3]--;
  }
  printf("%d", cnt[1] + cnt[3] - min(c3, c1));
}

/*
7
2 2 1 3 2 1 3

11
2 2 3 2 2 2 1 3 3 1 2
*/
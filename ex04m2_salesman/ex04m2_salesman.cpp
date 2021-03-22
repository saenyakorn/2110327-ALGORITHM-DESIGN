#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int min_walk(vector<int> &cost, int u, int v) {
  if (u > v) swap(u, v);
  int right = cost[v] - cost[u];
  return min(right, cost.back() - right);
}

int walk(vector<int> &cost, int u, int v, int A, int B) {
  // no portal
  int sol1 = min_walk(cost, u, v);
  // use protal
  int sol2 = min_walk(cost, u, A) + min_walk(cost, B, v);
  int sol3 = min_walk(cost, u, B) + min_walk(cost, A, v);
  return min(sol1, min(sol2, sol3));
}

int main() {
  int n, m, a, b, tmp;
  scanf("%d%d", &n, &m);
  vector<int> seq(m);
  for (int i = 0; i < m; i++)
    scanf("%d", &seq[i]);

  int acc = 0;
  vector<int> cost(m + 1, 0);
  for (int i = 1; i <= m; i++)
    scanf("%d", &tmp), acc += tmp, cost[i] = acc;

  // for (int i = 0; i <= m; i++) printf("%d\n", cost[i]);

  while (n--) {
    scanf("%d%d", &a, &b);
    int sum = 0;
    for (int i = 0; i < m; i++) {
      int w = walk(cost, seq[i], seq[(i + 1) % m], a, b);
      // printf("%d to %d walk %d\n", seq[i], seq[(i + 1) % m], w);
      sum += w;
    }
    printf("%d\n", sum);
  }
}

/*
1 4
0 1 2 3
5 3 3 3
0 1

2 4
0 2 1 3
5 6 7 3
0 1
2 3
*/
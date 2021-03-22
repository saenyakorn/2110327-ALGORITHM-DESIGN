#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi pareto(const vii& p, int lb, int ub) {
  if (ub - lb == 1) return vi(1, lb);
  int mid = (lb + ub) / 2;
  vi L = pareto(p, lb, mid), R = pareto(p, mid, ub);
  int maxY = 0;
  vi M = vi();
  for (int i = 0; i < R.size(); i++) maxY = max(maxY, p[R[i]].second);
  for (int i = 0; i < L.size(); i++)
    if (p[L[i]].second >= maxY) M.push_back(L[i]);
  for (int i = 0; i < R.size(); i++) M.push_back(R[i]);
  return M;
}

int main() {
  int n;
  scanf("%d", &n);
  vii p(n);
  for (int i = 0; i < n; i++) scanf("%d%d", &p[i].first, &p[i].second);
  sort(p.begin(), p.end());
  printf("%lu", pareto(p, 0, n).size());
}

/*
3
50 10
30 30
10 50

3
10 10
20 20
30 30

4
20 40
21 21
40 20
41 41
*/
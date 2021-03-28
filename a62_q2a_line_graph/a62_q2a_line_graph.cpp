#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool isLinear(vvi &G, vi &visit, vi &parent, int u) {
  visit[u] = 1;
  bool isL = true;
  if (G[u].size() > 2) isL = false;
  for (int i = 0; i < G[u].size() && isL; i++) {
    int v = G[u][i];
    if (parent[u] == v) continue;
    if (!visit[v]) {
      parent[v] = u, isL &= isLinear(G, visit, parent, v);
    } else {
      isL = false;
    }
  }
  return isL;
}

int main() {
  int N, E, u, v;
  cin >> N >> E;

  vvi G(N);
  while (E--) {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int cnt = 0;
  vi visit(N, 0), parent(N, 0);
  for (int i = 0; i < N; i++) parent[i] = i;
  for (int i = 0; i < N; i++) {
    if (visit[i]) continue;
    int tmp = isLinear(G, visit, parent, i);
    cnt += tmp;
  }
  cout << cnt << "\n";
}

/*
3 2
0 1
0 2

3 2
1 0
0 2

3 0

5 4
0 1
2 3
3 4
4 2

6 2
1 2
3 4

4 6
0 1
0 2
0 3
1 2
1 3
2 3
*/
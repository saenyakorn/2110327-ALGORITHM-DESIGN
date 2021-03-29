#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void dfs(vvi &G, vi &visit, int u) {
  if (!visit[u]) {
    visit[u] = 1;
    for (int i = 0; i < G[u].size(); i++) dfs(G, visit, G[u][i]);
  }
}

int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  int N, M, u, v;
  cin >> N >> M;
  vvi G(N + 1);
  while (M--) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
  vi visit(N, 0);
  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    if (visit[i]) continue;
    dfs(G, visit, i);
    cnt += 1;
  }
  cout << cnt << "\n";
}

/*
4 3
1 2
2 3
3 1

5 0

5 1
1 2

5 2
1 2
4 5

10 7
1 2
2 3
3 4
1 3
2 4
5 6
6 7
*/
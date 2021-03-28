#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int bfs(vvi &G, vi &visit, int K) {
  int cnt = 0;
  priority_queue<ii, vector<ii>, greater<ii> > PQ;
  PQ.push(ii(0, 0));
  while (!PQ.empty()) {
    ii tmp = PQ.top();
    int k = tmp.first, u = tmp.second;
    PQ.pop();
    if (!visit[u]) {
      visit[u] = 1;
      if (k == K) cnt += 1;
      for (int i = 0; i < G[u].size() && k < K; i++) {
        int v = G[u][i];
        PQ.push(ii(k + 1, v));
      }
    }
  }
  return cnt;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  int N, M, K, u, v;
  cin >> N >> M >> K;
  vvi G(N + 1);
  while (M--) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);

  vi visit(N + 1, 0);
  cout << bfs(G, visit, K) << "\n";
}

/*
3 4 1
0 1
1 2
1 3
0 3

5 0 1

3 4 2
0 1
1 2
2 3
1 3
*/
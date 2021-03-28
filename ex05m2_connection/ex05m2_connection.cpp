#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int visit[1001] = {0};

void bfs(vector<vi> &G, int u, int K) {
  queue<ii> Q;
  Q.push(ii(u, 0));
  while (!Q.empty()) {
    ii tmp = Q.front();
    Q.pop();
    int u = tmp.first, k = tmp.second;
    if (!visit[u] && k <= K) {
      visit[u] = 1;
      for (int i = 0; i < G[u].size(); i++)
        Q.push(ii(G[u][i], k + 1));
    }
  }
}

int walk_k_time(vector<vi> &G, int K) {
  int mx = 0;
  for (int u = 0; u < G.size(); u++) {
    int cnt = 0;
    for (int i = 0; i < G.size(); i++) visit[i] = 0;
    bfs(G, u, K);
    for (int i = 0; i < G.size(); i++) cnt += visit[i];
    mx = mx > cnt ? mx : cnt;
  }
  return mx;
}

int main() {
  int N, E, K;
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N >> E >> K;

  vector<vi> G(N);
  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  cout << walk_k_time(G, K) << "\n";
}

/*
7 8 2
0 6
1 6
1 5
1 4
2 3
3 4
4 5
5 6
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;

ll dfs(vvi &G, vi &parent, vi &cost, int u) {
  ll allChild = 0;
  if (!cost[u]) {
    cost[u] = 1;
    vi child;
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (!cost[v] && parent[u] != v) {
        parent[v] = u;
        int tmp = dfs(G, parent, cost, v);
        child.push_back(tmp);
        allChild += tmp;
      }
    }
    ll sum = 0;
    for (int i = 0; i < child.size(); i++)
      for (int j = i + 1; j < child.size(); j++) sum += child[i] * child[j];
    ll rest = G.size() - allChild - 1;
    cost[u] = allChild + rest + (rest * allChild) + sum;
  }
  return allChild + 1;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  int N, U, V;
  cin >> N;
  vvi G(N);
  vi parent(N, 0), cost(N, 0), child(N, 0);
  for (int i = 0; i < N; i++) parent[i] = i;
  for (int i = 0; i < N - 1; i++)
    cin >> U >> V, G[U].push_back(V), G[V].push_back(U);
  dfs(G, parent, cost, 0);
  for (int i = 0; i < N; i++) {
    cout << cost[i] << "\n";
  }
}

/*
4
0 1
0 2
0 3

10
2 9
6 9
0 6
2 7
6 8
2 5
2 4
1 4
3 6
*/
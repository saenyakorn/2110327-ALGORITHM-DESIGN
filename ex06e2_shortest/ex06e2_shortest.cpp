#include <climits>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void bellman(vector<vii>& G, vi& dist, int s) {
  int N = G.size();
  for (int k = 0; k < N - 1; k++) {
    for (int u = 0; u < N; u++) {
      for (int i = 0; i < G[u].size() && dist[u] != INT_MAX; i++) {
        int v = G[u][i].first, w = G[u][i].second;
        if (dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
        }
      }
    }
  }
  for (int i = 0; i < N; i++) {
    if (dist[i] == INT_MAX) {
      dist[i] = 0;
      bellman(G, dist, i);
      return;
    }
  }
  for (int u = 0; u < N; u++) {
    for (int i = 0; i < G[u].size() && dist[u] != INT_MAX; i++) {
      int v = G[u][i].first, w = G[u][i].second;
      if (dist[v] > dist[u] + w) {
        cout << "-1\n";
        return;
      }
    }
  }
  for (int i = 0; i < N; i++) cout << dist[i] << " ";
  cout << "\n";
}

int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  int N, E, S, U, V, W;
  cin >> N >> E >> S;
  vector<vii> G(N);
  while (E--) {
    cin >> U >> V >> W;
    G[U].push_back(ii(V, W));
  }
  vi dist(N, INT_MAX);
  dist[S] = 0;
  bellman(G, dist, S);
}

/*
4 3 0
0 1 -1
1 2 1
2 3 4

4 3 0
1 2 -1
2 3 -1
3 1 -1
*/
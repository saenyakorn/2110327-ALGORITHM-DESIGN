#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int findCycle(vvi &G, vi &visit, vi &parent, int u, int count = 0) {
  if (!visit[u]) {
    visit[u] = 1;
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (parent[u] == v) continue;
      parent[v] = u;
      if (visit[v]) return v;
      int tmp = findCycle(G, visit, parent, v, count + 1);
      if (tmp >= 0) return tmp;
    }
  }
  return -1;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  int N, u, v, cnt = 1;
  cin >> N;
  vvi G(N);
  vi visit(N, 0), parent(N);
  for (int i = 0; i < N; i++) parent[i] = i;
  while (N--) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
  int start = findCycle(G, visit, parent, 0);
  int next = parent[start];
  while (start != next) {
    next = parent[next];
    cnt += 1;
  }
  cout << cnt << "\n";
}

/*
9
0 1
0 2
1 3
1 4
2 5
2 6
2 7
4 5
5 8

5
2 4
4 0
0 1
1 2
2 3

7
0 6 
6 5
1 6
0 1
1 4 
1 2 
2 3

7
0 6 
6 5
1 6
0 3
1 4 
1 2 
2 3
*/
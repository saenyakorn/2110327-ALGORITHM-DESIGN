#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef vector<int> vi;

bool hasCycle(vector<vi> &G) {
  vector<int> parent(G.size(), -1), visit(G.size(), 0);
  stack<int> stk;
  for (int i = 0; i < G.size(); i++) {
    if (visit[i]) continue;
    parent[i] = i;
    stk.push(i);
    while (!stk.empty()) {
      int u = stk.top();
      stk.pop();
      if (!visit[u]) {
        visit[u] = 1;
        for (int i = 0; i < G[u].size(); i++) {
          int v = G[u][i];
          if (parent[u] == v) continue;
          if (parent[v] != -1) return true;
          parent[v] = u;
          stk.push(v);
        }
      }
    }
  }

  return false;
}

void start() {
  int N, E;
  scanf("%d%d", &N, &E);
  vector<vi> G(N);
  while (E--) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  cout << (hasCycle(G) ? "YES" : "NO") << "\n";
}

int main() {
  int k;
  scanf("%d", &k);
  while (k--) start();
}

/*
4
4 0
4 4
2 3
0 1
1 2
2 0
4 3
0 1
1 2
2 0
4 1
1 3
*/
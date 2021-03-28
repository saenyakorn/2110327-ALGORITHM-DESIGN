#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void dfs(vvi &G, vi &visit, stack<int> &stk, int u) {
  visit[u] = 1;
  for (int i = 0; i < G[u].size(); i++)
    if (!visit[G[u][i]]) dfs(G, visit, stk, G[u][i]);
  stk.push(u);
}

void topological(vvi &G) {
  int N = G.size();
  vi visit(N, 0);
  stack<int> stk;
  for (int i = 0; i < N; i++) {
    if (visit[i]) continue;
    dfs(G, visit, stk, i);
  }
  while (!stk.empty())
    cout << stk.top() << " ", stk.pop();
}

int main() {
  int N;
  cin >> N;
  vvi G(N);
  for (int i = 0; i < N; i++) {
    int m, u;
    cin >> m;
    while (m--) cin >> u, G[u].push_back(i);
  }
  topological(G);
}

/*
4
0
0
0
0

4
1 1
2 3 2
0
0
*/
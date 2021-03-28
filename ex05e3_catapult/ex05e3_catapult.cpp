#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void dfs(vvi &G, vi &visit, stack<int> &stk, int u) {
  visit[u] = 1;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (!visit[v]) dfs(G, visit, stk, v);
  }
  stk.push(u);
}

bool isAllTrue(vi &v) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == 0) return false;
  }
  return true;
}

int findLastOrder(vvi &RG, vi visit) {
  stack<int> stk;
  for (int i = 0; i < RG.size(); i++) {
    if (visit[i]) continue;
    dfs(RG, visit, stk, i);
  }
  return stk.top();
}

void detectSCC(vvi &G, vvi &RG) {
  int N = G.size();
  vi visit(N, 0);
  vvi scc;
  while (true) {
    stack<int> stk;
    int lastOrder = findLastOrder(RG, visit);
    dfs(G, visit, stk, lastOrder);
    scc.push_back(vector<int>());
    while (!stk.empty())
      scc.back().push_back(stk.top()), stk.pop();
    if (isAllTrue(visit)) break;
  }
  vi s;
  for (int i = 0; i < scc.size(); i++) s.push_back(scc[i].size());
  sort(s.begin(), s.end());
  for (int i = 0; i < s.size(); i++) cout << s[i] << " ";
}

int main() {
  int N;
  cin.tie(0), ios::sync_with_stdio(false);
  cin >> N;
  vvi G(N), RG(N);
  for (int i = 0; i < N; i++) {
    int m, v;
    cin >> m;
    for (int j = 0; j < m; j++) {
      cin >> v;
      G[i].push_back(v);
      RG[v].push_back(i);
    }
  }
  detectSCC(G, RG);
}

/*
3
1 1
1 2
1 0

3
1 1
1 0
0

5
2 1 2
2 0 3
1 3
1 2
0
*/
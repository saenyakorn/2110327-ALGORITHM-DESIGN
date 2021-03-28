#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

map<int, int> M, cnt, deep;

int dfs(vector<vi> &G, int u) {
  int maxDeep = 1;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    maxDeep = max(maxDeep, dfs(G, v) + 1);
  }
  return deep[u] = maxDeep;
}

void dfs(vector<vi> &G, vi &visit, vi &parent, int u) {
  if (!visit[u]) {
    visit[u] = 1;
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      parent[v] = u;
      if (!visit[v]) dfs(G, visit, parent, v);
    }
  }
}

void dfs(vector<vi> &G, vi &visit, stack<int> &stk, int u, int visitNum) {
  if (visit[u] == 0) {
    visit[u] = visitNum;
    for (int i = 0; i < G[u].size(); i++)
      if (!visit[G[u][i]]) dfs(G, visit, stk, G[u][i], visitNum);
    stk.push(u);
  }
}

int findLastOrder(vector<vi> &RG, vi &startCondition) {
  stack<int> stk;
  vi visit(startCondition);
  for (int i = 0; i < RG.size(); i++) {
    if (visit[i]) continue;
    dfs(RG, visit, stk, i, 1);
  }
  return stk.top();
}

vector<vi>
combineSC(vector<vi> &G, vector<vi> &RG) {
  int visitNum = 1;
  vector<vi> SC;
  stack<int> stk;
  vi visit(G.size(), 0);
  while (true) {
    int last = findLastOrder(RG, visit);
    dfs(G, visit, stk, last, visitNum++);
    vi tmp;
    while (!stk.empty()) tmp.push_back(stk.top()), stk.pop();
    SC.push_back(tmp);
    bool b = true;
    for (int i = 0; i < visit.size(); i++) b &= visit[i] == 0 ? false : true;
    if (b) break;
  }
  for (int i = 0; i < visit.size(); i++) visit[i] -= 1, cnt[visit[i]] += 1;
  vector<set<int> > tmpG(SC.size());
  for (int i = 0; i < SC.size(); i++) {
    for (int j = 0; j < SC[i].size(); j++) {
      int v = SC[i][j];
      for (int k = 0; k < RG[v].size(); k++) {
        int u = RG[v][k];
        tmpG[visit[u]].insert(visit[v]);
      }
    }
  }
  vector<vi> newG(tmpG.size());
  for (int i = 0; i < tmpG.size(); i++)
    for (set<int>::iterator itr = tmpG[i].begin(); itr != tmpG[i].end(); itr++)
      // if (*itr != i) newG[i].push_back(*itr);
      if (*itr != i) newG[*itr].push_back(i);
  return newG;
}

int main() {
  int N, E;
  cin >> N >> E;
  ios::sync_with_stdio(false), cin.tie(0);
  vector<vi> G(N);
  vector<vi> RG(N);
  while (E--) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    RG[v].push_back(u);
  }
  vector<vi> SC = combineSC(G, RG);
  vi visit(SC.size(), 0);
  for (int i = 0; i < visit.size(); i++) {
    if (visit[i]) continue;
    dfs(SC, i);
  }
  for (int i = 0; i < visit.size(); i++) M[deep[i]] += cnt[i];
  for (map<int, int>::iterator itr = M.begin(); itr != M.end(); itr++) {
    cout << itr->second << " ";
  }
}

/*
10 0

10 2
5 6
0 1

4 3
0 1
1 2
2 3

4 5
0 1
1 2
2 0
2 3
1 3

3 2
0 1
1 0

4 3
2 1
2 0
1 3

9 9
0 1 
1 2 
2 3 
3 0
3 4 
4 5 
5 6 
6 7 
7 5

4 3
0 3 
1 2 
2 3 
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef priority_queue<iii, vector<iii>, greater<iii> > pq;

iii mp3(int a, int b, int c) {
  return iii(a, ii(b, c));
}

void unionParent(int pu, int pv, vector<int> &height, vector<int> &parent) {
  if (height[pu] == height[pv]) {
    parent[pu] = pv;
    height[pv] += 1;
  } else if (height[pu] < height[pv]) {
    parent[pu] = pv;
  } else {
    parent[pv] = pu;
  }
}

int findParent(vector<int> &parent, int u) {
  if (parent[u] != u) return findParent(parent, parent[u]);
  return u;
}

int mst(vvii &G, pq &PQ) {
  int sum = 0, i = 0;
  int N = G.size();
  vector<int> parent(N), height(N);
  for (int i = 0; i < N; i++) parent[i] = i, height[i] = 0;
  while (i < N - 1) {
    iii edge = PQ.top();
    PQ.pop();
    int w = edge.first, u = edge.second.first, v = edge.second.second;
    int pu = findParent(parent, u), pv = findParent(parent, v);
    if (pu == pv) continue;
    sum += w, i++;
    unionParent(pu, pv, height, parent);
  }
  return sum;
}

int main() {
  int N, w;
  scanf("%d", &N);

  vvii G(N);
  pq E;
  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++)
      cin >> w, G[i].push_back(ii(j, w)), E.push(mp3(w, i, j));

  cout << mst(G, E);
}

/*
4
1 3 4
2 7 
6

5
4 3 6 7
4 2 5
6 5
7
*/
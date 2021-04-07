#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef pair<int, ii> iii;

iii mp3(int a, int b, int c) {
  return iii(a, ii(b, c));
}

int findParent(vi &parent, int u) {
  if (parent[u] != u) return findParent(parent, parent[u]);
  return u;
}

bool canAdd(vi &parent, vi &height, int u, int v) {
  int pu = findParent(parent, u), pv = findParent(parent, v);
  if (pu == pv) return false;
  if (height[pu] == height[pv]) {
    height[pv] += 1;
    parent[pu] = pv;
  } else if (height[pu] > height[pv]) {
    parent[pv] = pu;
  } else {
    parent[pu] = pv;
  }
  return true;
}

vi MBST(vvii &G, priority_queue<iii, vector<iii>, greater<iii> > &PQ) {
  int N = G.size(), k = 0;
  vi weight(N - 1, 0), parent(N), height(N, 0);
  for (int i = 0; i < N; i++) parent[i] = i;
  while (k < N - 1) {
    iii tmp = PQ.top();
    PQ.pop();
    int u = tmp.second.first, v = tmp.second.second, w = tmp.first;
    if (canAdd(parent, height, u, v)) {
      weight[k++] = w;
    }
  }
  sort(weight.begin(), weight.end());
  return weight;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  int N, M, Q, U, V, W, D;
  cin >> N >> M >> Q;
  vvii G(N);
  priority_queue<iii, vector<iii>, greater<iii> > PQ;
  while (M--) {
    cin >> U >> V >> W;
    G[U].push_back(ii(V, W)), G[V].push_back(ii(U, W));
    PQ.push(mp3(W, U, V));
  }
  vi mst = MBST(G, PQ);
  while (Q--) {
    cin >> D;
    cout << mst[mst.size() - D] << "\n";
  }
}

/*
5 6 4
0 1 20
0 2 10
2 3 30
1 3 10
2 4 40
3 4 50
1
2
3
4

*/
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
  int N, M, K, U, V;
  cin >> N >> M >> K;
  vi C(N), S(N), visit(N, 0), time(N, INT_MAX);
  vvi G(N);
  priority_queue<ii, vector<ii>, greater<ii> > PQ;
  for (int i = 0; i < K; i++) cin >> S[i];
  for (int i = 0; i < N; i++) cin >> C[i];
  for (int i = 0; i < K; i++) PQ.push(ii(time[S[i]] = C[S[i]], S[i]));
  while (M--) {
    cin >> U >> V;
    G[U].push_back(V);
    G[V].push_back(U);
  }
  while (!PQ.empty()) {
    int u = PQ.top().second;
    PQ.pop();
    if (!visit[u]) {
      visit[u] = 1;
      for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i], t = C[v];
        if (!visit[v] && time[v] > time[u] + t) {
          time[v] = time[u] + t;
          PQ.push(ii(time[v], v));
        }
      }
    }
  }
  int mx = 0;
  for (int i = 0; i < G.size(); i++)
    if (time[i] != INT_MAX) mx = mx > time[i] ? mx : time[i];
  cout << mx;
}

/*
3 2 1
1
3 5 1
0 1
1 2

4 4 1
0
2 5 3 1
0 1
0 2
1 3
2 3

4 3 2  
0 3
4 3 2 1
0 1
1 2
2 3
*/
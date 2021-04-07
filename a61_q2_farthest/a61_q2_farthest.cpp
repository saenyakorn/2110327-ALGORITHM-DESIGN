#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

int table[1002][1002] = {0};

ll shortest(int n) {
  vi visit(n, 0), dist(n, LLONG_MAX);
  dist[0] = 0;
  priority_queue<ii, vector<ii>, greater<ii> > PQ;
  PQ.push(ii(0, 0));
  while (!PQ.empty()) {
    int u = PQ.top().second;
    PQ.pop();
    if (!visit[u]) {
      visit[u] = 1;
      for (int i = 0; i < n; i++) {
        if (table[u][i] == -1) continue;
        if (!visit[i] && dist[i] > dist[u] + table[u][i]) {
          dist[i] = dist[u] + table[u][i];
          PQ.push(ii(dist[i], i));
        }
      }
    }
  }
  ll mx = LLONG_MIN;
  for (int i = 0; i < n; i++) {
    if (dist[i] == LLONG_MAX) return -1;
    mx = max(mx, dist[i]);
  }
  return mx;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> table[i][j];
  cout << shortest(n) << "\n";
}

/*
5 
0 1 -1 -1 7
-1 0 2 3 5
-1 -1 0 4 -1
-1 4 2 0 -1
-1 -1 -1 4 0
*/
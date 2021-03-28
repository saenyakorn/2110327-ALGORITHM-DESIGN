#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef pair<ull, ull> ii;
typedef vector<ull> vi;
typedef vector<vi> vvi;

ull table[2001][2001];

void generateGraph(vi &code) {
  for (int i = 0; i < code.size(); i++)
    for (int j = i + 1; j < code.size(); j++) table[i][j] = table[j][i] = (code[i] ^ code[j]);
}

ull mst(int N) {
  vi cost(N, 0), visit(N, 0);
  priority_queue<ii, vector<ii>, less<ii> > PQ;
  PQ.push(ii(0, 0));
  while (!PQ.empty()) {
    ii tmp = PQ.top();
    PQ.pop();
    int u = tmp.second;
    if (!visit[u]) {
      visit[u] = 1;
      for (int i = 0; i < N; i++) {
        if (!visit[i]) {
          cost[i] = max(cost[i], table[u][i]);
          PQ.push(ii(cost[i], i));
        }
      }
    }
  }
  ull sum = 0;
  for (int i = 0; i < N; i++) sum += cost[i];
  return sum;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vi code(N);
  for (int i = 0; i < N; i++) cin >> code[i];
  generateGraph(code);
  cout << mst(N) << "\n";
}

/*
4
3
10
9
6
*/
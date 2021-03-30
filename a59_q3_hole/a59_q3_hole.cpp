#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int table[1003][1003] = {0};
int mr[] = {0, 1, 0, -1}, mc[] = {1, 0, -1, 0};

bool canMove(int r, int c) {
  return 0 <= r && r <= 1000 && 0 <= c && c <= 1000 && table[r][c] != 1;
}

iii mp3(int a, int b, int c) { return iii(a, ii(b, c)); }

int main() {
  int N, a, b, u, v, result = 0;
  cin.tie(0), ios::sync_with_stdio(false);
  cin >> N >> a >> b;
  while (N--) cin >> u >> v, table[u][v] = -1;
  priority_queue<iii, vector<iii>, greater<iii> > PQ;
  PQ.push(mp3(0, a, b));
  while (!PQ.empty()) {
    iii tmp = PQ.top();
    PQ.pop();
    int fill = tmp.first, r = tmp.second.first, c = tmp.second.second;
    result = fill;
    if (r == 0 || r == 1000 || c == 0 || c == 1000) break;
    if (canMove(r, c)) {
      table[r][c] = 1;
      for (int i = 0; i < 4; i++) {
        int nextR = r + mr[i], nextC = c + mc[i];
        if (canMove(nextR, nextC)) {
          PQ.push(mp3(fill + (table[nextR][nextC] == -1), nextR, nextC));
        }
      }
    }
  }
  cout << result << "\n";
}

/*
7 6 3 
6 2 
5 2 
4 3 
2 1 
7 3 
5 4 
6 4
*/
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n, m;
int table[500][500] = {0};
int dist[500][500] = {0};
bool visit[500][500] = {0};
int mr[] = {1, 0, -1, 0};
int mc[] = {0, 1, 0, -1};

bool canMove(int r, int c) {
  return 0 <= r && r < n && 0 <= c && c < m;
}

iii mp3(int a, int b, int c) {
  return iii(a, ii(b, c));
}

void printTable() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << (dist[i][j] == INT_MAX ? 0 : dist[i][j]) << " ";
    cout << "\n";
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> table[i][j], dist[i][j] = INT_MAX;
  priority_queue<iii, vector<iii>, greater<iii> > PQ;
  PQ.push(mp3(0, 0, 0));
  dist[0][0] = 0;
  while (!PQ.empty()) {
    int r = PQ.top().second.first;
    int c = PQ.top().second.second;
    PQ.pop();
    if (!visit[r][c]) {
      visit[r][c] = 1;
      for (int i = 0; i < 4; i++) {
        int nR = r + mr[i], nC = c + mc[i];
        if (canMove(nR, nC) && !visit[nR][nC] && dist[nR][nC] > dist[r][c] + table[nR][nC]) {
          dist[nR][nC] = dist[r][c] + table[nR][nC];
          PQ.push(mp3(dist[nR][nC], nR, nC));
        }
      }
    }
  }
  printTable();
}

/*
4 4
1 1 1 1
9 8 7 1
1 1 1 1
1 2 4 9
*/
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

#define x first
#define y second.first
#define z second.second

int R, C, T;
int table[501][501] = {0};
int mx[] = {1, 0, -1, 0};
int my[] = {0, 1, 0, -1};

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

iii mp3(int a, int b, int c) {
  return iii(a, ii(b, c));
}

bool canWalk(int r, int c) {
  return 0 <= r && r < R && 0 <= c && c < C && table[r][c] != 2;
}

int bfs(queue<iii> &Q) {
  int cnt = 0;
  while (!Q.empty()) {
    iii cur = Q.front();
    Q.pop();
    int time = cur.x, r = cur.y, c = cur.z;
    if (table[r][c] != 0 || time > T) continue;
    table[r][c] = 1, cnt += 1;
    for (int i = 0; i < 4; i++) {
      int nextR = r + mx[i], nextC = c + my[i];
      if (canWalk(nextR, nextC)) {
        Q.push(mp3(time + 1, nextR, nextC));
      }
    }
  }
  return cnt;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> R >> C >> T;

  queue<iii> Q;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> table[i][j];
      if (table[i][j] == 1) {
        table[i][j] = 0;
        Q.push(mp3(0, i, j));
      }
    }
  }
  cout << bfs(Q) << "\n";
}
/*
5 4 3
0 0 0 0
0 0 0 0
0 0 0 0
0 2 1 0
0 0 0 0

3 3 2
0 0 1
0 0 0
0 0 1

1 12 3
0 1 0 0 0 0 0 0 0 1 0 0
*/
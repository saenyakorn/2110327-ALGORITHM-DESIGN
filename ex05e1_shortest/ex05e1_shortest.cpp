#include <iostream>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int R, C;
int table[101][101] = {0};
int mx[] = {1, 0, -1, 0}, my[] = {0, 1, 0, -1};

bool canWalk(int r, int c) {
  return 0 <= r && r < R && 0 <= c && c < C && table[r][c] > -2;
}

int walk() {
  if (table[0][0] != -1) return -1;
  queue<iii> Q;
  Q.push(iii(ii(0, 0), 0));
  while (!Q.empty()) {
    iii tmp = Q.front();
    Q.pop();
    ii pos = tmp.first;
    int time = tmp.second;
    if (table[pos.first][pos.second] != -1) continue;
    if (pos.first == R - 1 && pos.second == C - 1) return time;
    table[pos.first][pos.second] = time;
    for (int i = 0; i < 4; i++) {
      int nextR = pos.first + mx[i], nextC = pos.second + my[i];
      if (canWalk(nextR, nextC) && table[nextR][nextC] == -1)
        Q.push(iii(ii(nextR, nextC), time + 1));
    }
  }
  return -1;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  cin >> R >> C;
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      char tmp;
      cin >> tmp;
      table[r][c] = (tmp == '.' ? -1 : -2);
    }
  }
  cout << walk() << "\n";
}

/*
5 5
.....
.#...
.#...
.#.#.
...#.

5 5
.....
...##
...#.
..##.
.###.
*/
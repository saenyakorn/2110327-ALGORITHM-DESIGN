#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> iiii;

#define w first.first
#define x first.second
#define y second.first
#define z second.second

int R, C;
int table[101][101] = {0};
int moveR[] = {1, 0, -1, 0};
int moveC[] = {0, 1, 0, -1};

iiii mp4(int a, int b, int c, int d) {
  return iiii(ii(a, b), ii(c, d));
}

bool canMove(int r, int c) {
  return 0 <= r && r < R && 0 <= c && c < C && table[r][c] != -2;
}

void start() {
  char tmp;
  int n, T, r, c;
  cin >> R >> C >> n >> T >> r >> c;

  priority_queue<iiii, vector<iiii>, greater<iiii> > PQ;
  for (int i = 0; i < n; i++) {
    int ri, ci, ti;
    cin >> ti >> ri >> ci;
    PQ.push(mp4(ti, i + 1, ri, ci));
  }
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> tmp;
      table[i][j] = tmp == '.' ? -1 : -2;
    }
  }

  int pacId = 0;
  int countPac = 0;
  PQ.push(mp4(0, pacId, r, c));
  while (!PQ.empty()) {
    iiii u = PQ.top();
    PQ.pop();
    int ut = u.w, um = u.x, ur = u.y, uc = u.z;
    if (ut > T) continue;
    if (table[ur][uc] > pacId && um != pacId) continue;
    if (um == pacId && table[ur][uc] != -1) continue;
    //cout << "test: " << ut << " " << um << " " << ur << " " << uc << "\n";
    if (table[ur][uc] != -2) {
      if (table[ur][uc] == pacId && um != pacId) countPac -= 1;
      if (table[ur][uc] != pacId && um == pacId) countPac += 1;
      table[ur][uc] = um;
      for (int mv = 0; mv < 4 && ut + 1 <= T; mv++) {
        if (canMove(ur + moveR[mv], uc + moveC[mv])) {
          PQ.push(mp4(ut + 1, um, ur + moveR[mv], uc + moveC[mv]));
        }
      }
    }
  }
  // for (int i = 0; i < R; i++) {
  //   for (int j = 0; j < C; j++) cout << table[i][j] << " ";
  //   cout << "\n";
  // }
  cout << (countPac > 0 ? "YES" : "NO") << "\n";
}

int main() {
  int K;
  cin.tie(0), ios::sync_with_stdio(false);
  cin >> K;
  while (K--) start();
}

/*
3
2 5 1 1 0 2
0 0 2
.....
.....
2 5 1 1 0 2
1 0 2
.....
.....
2 5 4 1 0 2
1 0 2
1 0 3
1 0 1
1 1 2
.....
.....


2
5 5 2 10 2 2
0 0 0
0 4 4
.....
.###.
.#.#.
.###.
.....
5 5 2 4 2 2
0 0 0
0 4 4
.....
.###.
...#.
.###.
.....
*/
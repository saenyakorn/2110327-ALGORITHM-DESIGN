#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef pair<int, vvi> ivvi;

int mr[] = {1, 0, -1, 0};
int mc[] = {0, 1, 0, -1};

void print_puzzle(vvi& puzzle) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) cout << puzzle[i][j] << " ";
    cout << "\n";
  }
  cout << "----------\n";
}

int abs(int a) {
  return a > 0 ? a : -a;
}

bool can_move(int r, int c) {
  return 0 <= r && r < 4 && 0 <= c && c < 4;
}

ii find_position(int number) {
  return ii((number - 1) / 4, (number - 1) % 4);
}

ii find_zero(vvi& puzzle) {
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      if (!puzzle[i][j]) return ii(i, j);
  return ii(-1, -1);
}

int cost_function(vvi& puzzle) {
  int cost = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (puzzle[i][j]) {
        ii should_place = find_position(puzzle[i][j]);
        cost += abs(should_place.first - i) + abs(should_place.second - j);
      }
    }
  }
  return cost;
}

int least_cost(vvi& init_puzzle) {
  int min_move = INT_MAX;
  int init_cost = cost_function(init_puzzle);
  priority_queue<ivvi, vector<ivvi>, greater<ivvi> > pq;
  pq.push(ivvi(init_cost, init_puzzle));
  map<vvi, bool> visit;
  while (!pq.empty()) {
    ivvi top = pq.top();
    pq.pop();
    int cost = top.first;
    vvi puzzle(top.second);
    int cal_cost = cost_function(puzzle);
    int move = cost - cal_cost;
    if (visit.find(puzzle) != visit.end()) continue;
    visit[puzzle] = 1;
    if (cal_cost == 0) return move;
    ii pos = find_zero(puzzle);
    int r = pos.first, c = pos.second;
    for (int i = 0; i < 4; i++) {
      int next_r = r + mr[i], next_c = c + mc[i];
      if (can_move(next_r, next_c)) {
        swap(puzzle[r][c], puzzle[next_r][next_c]);
        if (visit.find(puzzle) == visit.end()) {
          cost = cost_function(puzzle);
          pq.push(ivvi(move + 1 + cost, puzzle));
        }
        swap(puzzle[r][c], puzzle[next_r][next_c]);
      }
    }
  }
  return min_move;
}

int main() {
  vvi puzzle(4, vi(4));
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) cin >> puzzle[i][j];

  cout << least_cost(puzzle);
}

/*
1 2 3 4
5 6 7 8
9 10 11 0
13 14 15 12
*/
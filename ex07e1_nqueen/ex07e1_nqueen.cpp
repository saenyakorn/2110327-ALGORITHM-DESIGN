#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef vector<int> vi;

int abs(int a) {
  return a > 0 ? a : -a;
}

bool is_valid(vi pos) {
  int index_back = pos.size() - 1, back = pos.back();
  for (int i = 0; i < pos.size() - 1; i++)
    if (back == pos[i] || back - index_back == pos[i] - i || back + index_back == pos[i] + i) return false;
  return true;
}

int count(int n, vi &pos) {
  if (pos.size() == n) {
    return 1;
  }
  int acc = 0;
  for (int i = 0; i < n; i++) {
    pos.push_back(i);
    if (is_valid(pos))
      acc += count(n, pos);
    pos.pop_back();
  }
  return acc;
}

int main() {
  int n;
  cin >> n;
  vi position;
  cout << count(n, position);
}
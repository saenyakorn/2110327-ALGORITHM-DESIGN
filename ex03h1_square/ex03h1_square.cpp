#include <algorithm>
#include <iostream>

int t[1002][1002] = {0};

using namespace std;

int main() {
  int r, c, mx = 0;
  ios::sync_with_stdio(false);
  cin >> r >> c;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      char x;
      cin >> x;
      t[i][j] = x - '0';
      if (t[i][j] && t[i - 1][j] && t[i][j - 1] && t[i - 1][j - 1])
        t[i][j] = min(min(t[i - 1][j - 1], t[i - 1][j]), t[i][j - 1]) + 1;
      mx = max(mx, t[i][j]);
    }
  }
  cout << mx;
}

/*
5 5
00010
01111
00111
00111
00111

6 7
1111111
1111111
1001111
1111111
1110011
1011011

1 10
1111111011
*/
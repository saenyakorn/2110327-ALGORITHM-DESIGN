#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int t[n][n], mx = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) t[i][j] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      scanf("%d", &t[i][j]);
      if (i > 0) {
        t[i][j] += j > 0 ? max(t[i - 1][j - 1], t[i - 1][j]) : t[i - 1][j];
        mx = max(mx, t[i][j]);
      }
    }
  }
  printf("%d\n", mx);
}

/*
2
10 
20 30

5
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5
*/
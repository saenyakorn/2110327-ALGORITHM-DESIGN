#include <climits>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

int ones(int n) {
  if (n <= 6)
    return n;
  else if (n < 11)
    return ones(11 - n) + 2;
  int one = 1, i = 1;
  while (one < n) one = one * 10 + 1, i++;
  int prev = one / 10;
  i--;
  int x = ones(n - prev) + i;
  int y = 0 <= one - n && one - n < n ? ones(one - n) + i + 1 : INT_MAX;
  return min(x, y);
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", ones(n));
}

/*
121
11
1
2
5
6
7
30
*/
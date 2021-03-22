#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> v(4, 0);

int index(int t) {
  int inx = lower_bound(v.begin(), v.end(), t) - v.begin();
  return v[inx] == t ? inx : inx - 1;
}

int main() {
  int n, t;
  scanf("%d", &n);
  v[1] = 1, v[2] = 2, v[3] = 4;
  while (n--) {
    scanf("%d", &t);
    while (t >= v.back()) {
      int last = v.size() - 1;
      int add = index(last);
      v.push_back(v.back() + add);
    }
    printf("%d\n", index(t));
  }
}

/*
3
2 4 10

4
100 9999 123456 1000000000
*/
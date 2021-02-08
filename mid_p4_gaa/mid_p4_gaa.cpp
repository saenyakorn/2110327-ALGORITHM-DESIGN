#include <cstdio>
#include <vector>

using namespace std;

void find(vector<int>& v, int p, int n) {
  if (p > 0) {
    int l = v[p - 1], m = p + 3;
    if (n <= l)
      find(v, p - 1, n);
    else if (n <= l + m) {
      printf("%s\n", n == l + 1 ? "g" : "a");
    } else
      find(v, p - 1, n - m - l);
  } else
    printf("%s\n", n == 1 ? "g" : "a");
}

int main() {
  int n, len = 3;
  scanf("%d", &n);
  vector<int> v;
  v.push_back(len);
  for (int i = 1; len < n; i++) len = len * 2 + i + 3, v.push_back(len);
  find(v, v.size() - 1, n);
}
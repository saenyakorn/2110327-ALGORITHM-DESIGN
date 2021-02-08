#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int>::iterator it;

int find(vector<int> &arr, int m) {
  int n = arr.size();
  for (it i = arr.begin(); i < arr.end() - 2; i++) {
    it j = i + 1, k = arr.end() - 1;
    int sum;
    while (j < k) {
      sum = *i + *j + *k;
      if (sum == m) return !printf("YES\n");
      if (sum > m)
        k--;
      else
        j++;
    }
  }
  return !printf("NO\n");
}

int main() {
  int n, m, k;
  scanf("%d%d", &n, &m);
  vector<int> arr(n);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  while (m--) {
    scanf("%d", &k);
    find(arr, k);
  }
}

/*
4 5
-2 1 5 6
1 3 5 6 7
*/
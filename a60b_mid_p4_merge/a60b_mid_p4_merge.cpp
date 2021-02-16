#include <cstdio>
#include <stack>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int, int> ii;

int k;
stack<ii> stk;

void mergeSort(int lb, int ub) {
  if (k == 0 || ub - lb == 1) return;
  int mid = (lb + ub) / 2;
  k -= 2;
  stk.push(ii(lb, mid));
  stk.push(ii(mid, ub));
  mergeSort(lb, mid);
  mergeSort(mid, ub);
}

int main() {
  int n, x = 1;
  scanf("%d%d", &n, &k);
  if (k % 2 == 0) return !printf("-1");
  k -= 1;
  stk.push(ii(0, n));
  mergeSort(0, n);
  vector<int> v(n, -1);
  while (!stk.empty()) {
    ii p = stk.top();
    stk.pop();
    //printf("point: %d %d\n", p.first, p.second);
    if (v[p.first] == -1) {
      for (int i = p.first; i < p.second; i++) v[i] = x++;
    }
  }
  if (k > 0) return !printf("-1");
  for (int i = 0; i < n; i++) printf("%d ", v[i]);
}

/*
3 3

4 1

5 6 

10 5
*/
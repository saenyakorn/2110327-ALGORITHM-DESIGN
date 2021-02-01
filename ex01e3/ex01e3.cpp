#include <cstdio>
#include <vector>

using namespace std;

int bsearch_near(const vector<int> &arr, int first, int last, int p) {
  if (p < arr[first]) return -1;
  if (first == last - 1) {
    return p >= arr[first] ? arr[first] : -1;
  } else {
    int mid = (first + last) / 2;
    int r = bsearch_near(arr, mid, last, p);
    if (r != -1) return r;
    int l = bsearch_near(arr, first, mid, p);
    if (l != -1) return l;
    return -1;
  }
}

int main() {
  int N, M, p;
  scanf("%d%d", &N, &M);

  vector<int> V(N);
  for (int i = 0; i < N; i++) scanf("%d", &V[i]);

  for (int i = 0; i < M; i++) {
    scanf("%d", &p);
    printf("%d\n", bsearch_near(V, 0, N, p));
  }
}

/*
4 7
14 15 20 30
10 11 14 15 16 21 68
*/
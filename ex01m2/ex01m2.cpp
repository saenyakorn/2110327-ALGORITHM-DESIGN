#include <cstdio>
#include <vector>

using namespace std;

int inversion_count(vector<int> &V, int begin, int end) {
  int count = 0;
  vector<int> temp(end - begin + 1);
  int mid = (begin + end) / 2, p = begin, q = mid, tdx = 0;
  while (p < mid && q < end) {
    if (V[p] <= V[q]) {
      temp[tdx++] = V[p++];
    } else {
      count += mid - p;
      temp[tdx++] = V[q++];
    }
  }
  while (p < mid) temp[tdx++] = V[p++];
  while (q < end) temp[tdx++] = V[q++];
  for (int i = begin; i < end; i++) V[i] = temp[i - begin];
  return count;
}

int inversion(vector<int> &V, int begin, int end) {
  if (begin != end - 1) {
    int mid = (begin + end) / 2;
    int l = inversion(V, begin, mid);
    int r = inversion(V, mid, end);
    return inversion_count(V, begin, end) + l + r;
  }
  return 0;
}

int main() {
  int N;
  scanf("%d", &N);

  vector<int> V(N);
  for (int i = 0; i < N; i++) scanf("%d", &V[i]);

  printf("%d\n", inversion(V, 0, N));
}

/*
4
10 30 40 20

6
1 5 4 2 3 -1
*/
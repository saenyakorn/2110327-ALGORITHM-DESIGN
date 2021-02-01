#include <cstdio>
#include <vector>

using namespace std;

int mss(vector<int> &S, int lb, int ub) {
  if (lb == ub) return S[lb];
  int mid = (lb + ub) / 2;
  int l = mss(S, lb, mid);
  int r = mss(S, mid + 1, ub);
  int max_l = S[mid] - S[lb - 1];
  for (int i = lb - 1; i < mid; i++) {
    //printf("left %d %d %d\n", i, mid, S[mid] - S[i]);
    max_l = max(max_l, S[mid] - S[i]);
  }
  int max_r = S[ub] - S[mid];
  for (int i = mid; i < ub; i++) {
    //printf("right %d %d %d\n", mid, i, S[i] - S[mid]);
    max_r = max(max_r, S[i] - S[mid]);
  }
  return max(max(max_l + max_r, l), r);
}

int main() {
  int N, num;
  scanf("%d", &N);
  vector<int> S(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &num);
    S[i] = S[i - 1] + num;
  }
  printf("%d\n", mss(S, 1, N));
}

/*
15
1 2 -1 5 3 -8 -2 4 3 -4 -5 7 -1 -2 4

8
-1 -2 -2 -2 -2 -2 -2 -1

10
1 2 3 4 5 6 7 8 9 10
*/
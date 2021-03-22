#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

#define x first
#define y second

typedef pair<double, double> dd;

bool cmp(dd a, dd b) {
  double A = a.x / a.y, B = b.x / b.y;
  return A > B;
}

int main() {
  double W;
  int N;
  scanf("%lf%d", &W, &N);
  vector<dd> k(N);
  for (int i = 0; i < N; i++) scanf("%lf", &k[i].x);
  for (int i = 0; i < N; i++) scanf("%lf", &k[i].y);
  sort(k.begin(), k.end(), cmp);
  double value = 0;
  for (int inx = 0; inx < N; inx++) {
    if (k[inx].y <= W) {
      value += k[inx].x;
      W -= k[inx].y;
    } else {
      value += (k[inx].x / k[inx].y) * W;
      break;
    }
  }
  printf("%.4lf\n", value);
}

/*
6 3
5 3 3
4 3 3

5.5 4
2 3 4 5
1 2 3 4
*/
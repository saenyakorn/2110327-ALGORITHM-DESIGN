#include <algorithm>
#include <climits>
#include <cstdio>
#include <vector>

using namespace std;

double avg(vector<long long> &v) {
  double sum = 0;
  for (int i = 0; i < v.size(); i++) sum += v[i];
  return sum / v.size();
}

int findMin(vector<int> &v) {
  int mn = INT_MAX;
  for (int i = 0; i < v.size(); i++)
    if (v[i] > 0) mn = min(mn, v[i]);
  return mn;
}

int main() {
  int n, m, task = 0;
  long long acc = 0;
  scanf("%d %d", &n, &m);
  vector<int> v(m);
  vector<long long> f;
  for (int i = 0; i < m; i++) scanf("%d", &v[i]);
  sort(v.begin(), v.end());
  vector<int> work(n);
  for (int i = 0; i < n; i++, task++) work[i] = v[i];
  while (f.size() < m) {
    int mn = findMin(work);
    for (int i = 0; i < n; i++) {
      if (mn == work[i]) {
        f.push_back(acc + work[i]);
        work[i] = task < m ? v[task++] : 0;
      } else if (work[i] != 0) {
        work[i] -= mn;
      }
    }
    acc += mn;
  }
  printf("%.2lf\n", avg(f));
}

/*
1 4
3 9 4 2

3 10
4 3 2 4 1 2 5 3 4 5
*/
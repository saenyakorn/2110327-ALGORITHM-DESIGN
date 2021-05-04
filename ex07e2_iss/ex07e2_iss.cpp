#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<vector<int>, int> mp;

long long find_ans(int n, int acc, vector<int> &v) {
  if (acc == n) {
    // for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    // cout << "\n";
    return 1;
  }
  int sum = 0;
  int back = v.empty() ? 1 : v.back();
  for (int i = back; acc + i <= n; i++) {
    v.push_back(i);
    sum += find_ans(n, acc + i, v);
    v.pop_back();
  }
  return sum;
}

long long cal(int n) {
  vector<int> v;
  return find_ans(n, 0, v);
}

int main() {
  int n;
  cin >> n;
  cout << cal(n);
}
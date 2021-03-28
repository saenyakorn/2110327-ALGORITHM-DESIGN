#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool isValid(vvi &G, vi &task) {
  vi done(G.size(), 0);
  for (int i = 0; i < task.size(); i++) {
    int cur = task[i];
    for (int i = 0; i < G[cur].size(); i++)
      if (!done[G[cur][i]]) return false;
    done[cur] = 1;
  }
  return true;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  int N, E, u, v;
  cin >> N >> E;
  vvi G(N + 1);
  while (E--) cin >> v >> u, G[u].push_back(v);

  for (int i = 0; i < 5; i++) {
    vector<int> task(N);
    for (int j = 0; j < N; j++) cin >> task[j];
    cout << (isValid(G, task) ? "SUCCESS" : "FAIL") << "\n";
  }
}

/*
4 3
1 2
2 3
3 4
1 2 3 4
1 3 4 2
1 4 2 3
4 3 2 1
3 1 2 4

5 0
1 2 3 4 5
5 1 3 2 4
3 2 4 1 5
5 2 3 1 4
4 3 2 1 5

3 2
1 2
1 3
1 2 3
1 3 2
2 1 3
2 3 1
3 2 1
*/
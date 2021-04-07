#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
typedef pair<double, int> di;
double weight[502][502] = {0};
double dist[502][502] = {0};
bool visit[502] = {0};
double h[502] = {0};

void printTable(int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) cout << weight[i][j] << " ";
    cout << "\n";
  }
  cout << "---------------\n";
}

void printDist(int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) cout << dist[i][j] << " ";
    cout << "\n";
  }
  cout << "---------------\n";
}

bool floyd(int N) {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      dist[i][j] = weight[i][j];

  for (int k = 0; k < N; k++) {
    for (int u = 0; u < N; u++) {
      for (int v = 0; v < N; v++) {
        if (dist[u][k] + dist[k][v] < dist[u][v])
          dist[u][v] = dist[u][k] + dist[k][v];
      }
    }
  }

  for (int i = 0; i < N; i++)
    if (dist[i][i] < 0) return true;
  return false;
}

bool findAns(int N) {
  bool result = floyd(N);
  if (result) return true;
  for (int u = 0; u < N; u++) {
    for (int v = 0; v < N; v++) {
      if (dist[u][v] + weight[v][u] < 0) return true;
    }
  }
  return false;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(false);
  int K, N;
  cin >> K;
  while (K--) {
    cin >> N;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> weight[i][j];
        weight[i][j] = -log10(weight[i][j]);
      }
    }
    cout << (findAns(N) ? "YES\n" : "NO\n");
  }
}

/*
2
3
1 0.7 1.2
1.1 1 2
0.75 0.7 1
2
1 0.7
1.2 1

1
4
1 100 0.1 0.1
100 1 0.1 0.1
0.1 0.1 1 0.1
0.1 0.1 0.1 1
*/
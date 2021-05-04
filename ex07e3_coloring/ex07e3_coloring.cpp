#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<int, vi> ivi;

int find_max_color(vi& color) {
  int mx = 0;
  for (int i = 0; i < color.size(); i++) mx = max(mx, color[i]);
  return mx;
}

int find_zero(vi& color) {
  for (int i = 0; i < color.size(); i++)
    if (!color[i]) return i;
  return -1;
}

bool valid_color(vvi& graph, vi& color, int u) {
  for (int i = 0; i < graph[u].size(); i++)
    if (color[graph[u][i]] == color[u]) return false;
  return true;
}

int cost_function(vi& color) {
  map<int, int> mp;
  for (int i = 0; i < color.size(); i++) mp[color[i]] = 1;
  return mp.size();
}

int least_cost_search(vvi& graph) {
  int min_color = graph.size();
  vi init_color(graph.size(), 0);
  priority_queue<ivi, vector<ivi>, greater<ivi> > pq;
  pq.push(ivi(1, init_color));
  while (!pq.empty()) {
    ivi top = pq.top();
    pq.pop();
    int cost = top.first;
    vi color = top.second;
    if (cost > min_color) continue;
    int zero_pos = find_zero(color);
    int max_color = find_max_color(color);
    if (zero_pos == -1) {
      min_color = min(min_color, top.first);
      continue;
    }
    for (int i = 1; i <= max_color + 1; i++) {
      color[zero_pos] = i;
      if (valid_color(graph, color, zero_pos)) {
        pq.push(ivi(cost_function(color), color));
      }
    }
  }
  return min_color;
}

int main() {
  int N, E, u, v;
  cin >> N >> E;
  vvi graph(N);
  for (int i = 0; i < E; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  cout << least_cost_search(graph) << "\n";
}

/*

*/
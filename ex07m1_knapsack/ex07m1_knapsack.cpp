#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef pair<double, double> dd;
typedef vector<dd> vdd;
typedef pair<double, vector<dd> > dvdd;

#define x first
#define y second

void print_items(vdd& items) {
  for (int i = 0; i < items.size(); i++) cout << items[i].x << " ";
  cout << "\n";
  for (int i = 0; i < items.size(); i++) cout << items[i].y << " ";
  cout << "\n-------------\n";
}

bool cmp(dd a, dd b) {
  return (a.x / a.y) > (b.x / b.y);
}

double cal_value(vdd& items) {
  double value = 0;
  for (int i = 0; i < items.size(); i++)
    value += items[i].x;
  return value;
}

double cal_weight(vdd& items) {
  double weight = 0;
  for (int i = 0; i < items.size(); i++)
    weight += items[i].y;
  return weight;
}

double fractional_knp(vdd& items, int start, double capacity) {
  double value = 0;
  for (int i = start; i < items.size() && capacity; i++) {
    if (items[i].y <= capacity) {
      value += items[i].x;
      capacity -= items[i].y;
    } else {
      value += capacity * items[i].x / items[i].y;
      capacity = 0;
    }
  }
  return value;
}

double one_zero_knp(vdd& init_items, double capacity) {
  double max_cost = 0, n = init_items.size();
  priority_queue<dvdd, vector<dvdd>, less<dvdd> > pq;
  pq.push(dvdd(fractional_knp(init_items, 0, capacity), vdd()));
  while (!pq.empty()) {
    dvdd top = pq.top();
    pq.pop();
    double cost = top.first;
    vdd items(top.second);
    // print_items(items);
    if (cost < max_cost) continue;
    int index = items.size();
    double value = cal_value(items), weight = cal_weight(items);
    if (items.size() == n) {
      max_cost = max(max_cost, value);
    } else {
      if (init_items[index].y + weight <= capacity) {
        items.push_back(init_items[index]);
        cost = fractional_knp(init_items, index + 1, capacity - weight - init_items[index].y);
        pq.push(dvdd(value + init_items[index].x + cost, items));
        items.pop_back();
      }
      cost = fractional_knp(init_items, index + 1, capacity - weight);
      items.push_back(dd(0, 0));
      pq.push(dvdd(value + cost, items));
      items.pop_back();
    }
  }
  return max_cost;
}

int main() {
  int n;
  double capacity;
  cin >> capacity >> n;
  vdd items(n);
  for (int i = 0; i < n; i++) cin >> items[i].x;
  for (int i = 0; i < n; i++) cin >> items[i].y;
  sort(items.begin(), items.end(), cmp);
  cout << std::fixed << setprecision(4) << one_zero_knp(items, capacity) << "\n";
}

/*
10.0 4
1.2 3.4 6.3 1.3
4.2 1.4 6.7 4.3
*/
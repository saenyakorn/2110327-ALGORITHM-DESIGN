#include <cstdio>
#include <utility>
#include <vector>

#define x first
#define y second.first
#define z second.second

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

vector<iii> v;

void tile(int xlb, int ylb, int L, int X, int Y) {
  //printf("(%d %d %d) (%d %d)\n", xlb, ylb, L, X, Y);
  if (L == 2) {
    int type = 0;
    for (int i = 0; i < 4; i++)
      if (xlb + (i % 2) == X && ylb + (i / 2) == Y) type = i;
    v.push_back(iii(type, ii(xlb, ylb)));
  } else {
    int place;
    int midX = (2 * xlb + L - 1) / 2;
    int midY = (2 * ylb + L - 1) / 2;
    if (X <= midX && Y <= midY)
      place = 0;  // Top left
    else if (X > midX && Y <= midY)
      place = 1;  // Top right
    else if (X <= midX && Y > midY)
      place = 2;  // Bottom left
    else if (X > midX && Y > midY)
      place = 3;  // Bottom right
    v.push_back(iii(place, ii(midX, midY)));
    place == 0 ? tile(xlb, ylb, L / 2, X, Y) : tile(xlb, ylb, L / 2, midX, midY);
    place == 1 ? tile(midX + 1, ylb, L / 2, X, Y) : tile(midX + 1, ylb, L / 2, midX + 1, midY);
    place == 2 ? tile(xlb, midY + 1, L / 2, X, Y) : tile(xlb, midY + 1, L / 2, midX, midY + 1);
    place == 3 ? tile(midX + 1, midY + 1, L / 2, X, Y) : tile(midX + 1, midY + 1, L / 2, midX + 1, midY + 1);
  }
}

int main() {
  int L, X, Y;
  scanf("%d%d%d", &L, &X, &Y);
  tile(0, 0, L, X, Y);
  printf("%lu\n", v.size());
  for (int i = 0; i < v.size(); i++) printf("%d %d %d\n", v[i].x, v[i].y, v[i].z);
}
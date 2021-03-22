#include <cstdio>
#include <vector>

using namespace std;

int M[1 << 8][1 << 8];

void matrix(int X, int Y, int a, int b) {
  if (a == 0)
    M[X][Y] = b;
  else {
    int midX = X + (1 << (a - 1));
    int midY = Y + (1 << (a - 1));
    matrix(X, Y, a - 1, b);
    matrix(X, midY, a - 1, b - 1);
    matrix(midX, Y, a - 1, b + 1);
    matrix(midX, midY, a - 1, b);
  }
}

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  matrix(0, 0, a, b);
  for (int i = 0; i < (1 << a); i++) {
    for (int j = 0; j < (1 << a); j++) printf("%d ", M[i][j]);
    printf("\n");
  }
}

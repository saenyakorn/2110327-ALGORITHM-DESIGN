#include <cstdio>
#include <string>
#include <vector>

using namespace std;

void barcode(int A, int B, vector<char> &v) {
  if (B > 0) {
    if (A > 0) {
      v.push_back('1');
      barcode(A - 1, B - 1, v);
      v.pop_back();
    }
    v.push_back('0');
    barcode(A, B - 1, v);
    v.pop_back();
  } else if (A == 0) {
    for (int i = 0; i < v.size(); i++) printf("%c", v[i]);
    printf("\n");
  }
}

int main() {
  int A, B;
  scanf("%d%d", &A, &B);
  vector<char> v;
  barcode(A, B, v);
}
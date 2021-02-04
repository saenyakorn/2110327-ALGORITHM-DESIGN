#include <iostream>
#include <string>

using namespace std;

bool equal(string &a, int ia, int ja, string &b, int ib, int jb) {
  for (; ia < ja && ib < jb; ia++, ib++) {
    if (a[ia] != b[ib]) return false;
  }
  return true;
}

bool similar(string &a, int lba, int uba, string &b, int lbb, int ubb) {
  if (lba < uba - 1 && lbb < ubb - 1) {
    int mida = (lba + uba) / 2;
    int midb = (lbb + ubb) / 2;
    if (equal(a, lba, uba, b, lbb, ubb)) return true;
    if (similar(a, lba, mida, b, lbb, midb) && similar(a, mida, uba, b, midb, ubb)) return true;
    if (similar(a, lba, mida, b, midb, ubb) && similar(a, mida, uba, b, lbb, midb)) return true;
  }
  return equal(a, lba, uba, b, lbb, ubb);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  printf("%s\n", similar(a, 0, a.size(), b, 0, b.size()) ? "YES" : "NO");
}

/*
aaba
abaa

aabb
abab
*/
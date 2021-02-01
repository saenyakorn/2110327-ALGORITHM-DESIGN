#include <cstdio>
#include <vector>

using namespace std;

unsigned long long findIndex(vector<unsigned long long> &v, unsigned long long t) {
  unsigned long long index = 0;
  for (unsigned long long i = 0; i < v.size(); i++) index += t / v[i];
  return index;
}

unsigned long long searchTime(vector<unsigned long long> &v, unsigned long long lb, unsigned long long ub, unsigned long long p) {
  if (lb < ub) {
    unsigned long long mid = (lb + ub) / 2;
    unsigned long long seat = findIndex(v, mid);
    if (p <= seat)
      return searchTime(v, lb, mid, p);
    else
      return searchTime(v, mid + 1, ub, p);
  }
  return lb;
}

unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (b > 0) return gcd(b, a % b);
  return a;
}

unsigned long long lcm(unsigned long long a, unsigned long long b) {
  return a * b / gcd(a, b);
}

int main() {
  unsigned long long N, A, p;
  scanf("%llu%llu", &N, &A);

  vector<unsigned long long> v(N);
  unsigned long long m = 0;
  for (unsigned long long i = 0; i < N; i++) {
    scanf("%llu", &v[i]);
    m = i == 0 ? v[i] : lcm(m, v[i]);
  }

  unsigned long long total = 0;
  for (unsigned long long i = 0; i < N; i++) {
    total += m / v[i];
  }

  while (A--) {
    scanf("%llu", &p);
    unsigned long long round = ((p - N) / total);
    unsigned long long addTime = m * round;
    //printf("p = %llu total = %llu, round = %llu, addTime = %llu, seq = %llu\n", p, total, round, addTime, (p - N) % total);
    if (p > N) {
      printf("%llu\n", searchTime(v, 0, m, ((p - N) % total)) + addTime);
    } else
      printf("0\n");
  }
}

/*
3 5
2 2 5
4 5 6 30 123456789012

3 5
2 2 5
4 5 6 27 123456789012

3 20
2 2 5
2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40
*/
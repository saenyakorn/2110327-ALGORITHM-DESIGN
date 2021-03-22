#include <cstdio>

using namespace std;

int v[502], w[502], ans[502] = {0}, dp[502][502];

void findItems(int n, int m) {
  int idx = 0;
  while (m > 0) {
    while (dp[n][m] == dp[n - 1][m] && n > 0) n -= 1;
    if (n == 0) break;
    m -= w[n];
    ans[idx++] = n--;
  }
  printf("%d\n", idx);
  while (idx > 0) printf("%d ", ans[--idx]);
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", v + i);
  for (int i = 1; i <= n; i++) scanf("%d", w + i);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) scanf("%d", &dp[i][j]);
  findItems(n, m);
}

/*
5 5                           
3 10 6 3 5                    
5 5 3 1 1                     
0 0 0 0 0 0                   
0 0 0 0 0 3                   
0 0 0 0 0 10                  
0 0 0 6 6 10                  
0 3 3 6 9 10                  
0 5 8 8 11 14

5 3 
6 9 5 4 3 
2 3 1 1 2 
0 0 0 0 
0 0 6 6 
0 0 6 9 
0 5 6 11 
0 5 9 11 
0 5 9 11

3 5 
2 2 4 
1 4 5 
0 0 0 0 0 0 
0 2 2 2 2 2 
0 2 2 2 2 4 
0 2 2 2 2 4
*/
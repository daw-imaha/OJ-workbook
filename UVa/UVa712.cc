#include <cstdio>
#include <cstring>

int n, m, order[10];
char x[3], v[130], VVA[10], ans[130];

int main() {
  int kase = 0;
  while (scanf("%d", &n) && n) {
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n; ++i) {
      scanf("%s", x);
      order[i] = x[1] - '1';
    }
    scanf("%s%d", v, &m);
    for (int i = 0; i < m; ++i) {
      int k = 1;
      scanf("%s", VVA);
      for (int j = 0; j < n; ++j) k = 2 * k + VVA[order[j]] - '0';
      ans[i] = v[k - (1 << n)];
    }
    printf("S-Tree #%d:\n%s\n\n", ++kase, ans);
  }
  return 0;
}

#include <cstdio>
#include <cmath>

const int MOD = 1e3;
const int maxn = 2e4 + 5;
int p[maxn], d[maxn];

int find(int u) {
  if (p[u] == u) return u;
  int v = find(p[u]);
  d[u] += d[p[u]];
  return p[u] = v;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    char s[5];
    int N, u, v;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) { p[i] = i; d[i] = 0; }
    while (scanf("%s", s) && s[0] != 'O') {
      scanf("%d", &u);
      if (s[0] == 'E') { find(u); printf("%d\n", d[u]); }
      else { scanf("%d", &v); p[u] = v; d[u] = abs(u - v) % MOD; }
    }
  }
  return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 5005;
int p[2][maxn], vis[2][maxn], ok;

struct Interval {
  int l, r, id;
  bool operator<(const Interval& rhs) const {
    return r < rhs.r || r == rhs.r && l < rhs.l;
  }
} I[2][maxn];

void place(int i, int j) {  
  for (int k = I[i][j].l; k <= I[i][j].r; ++k) {
    if (!vis[i][k]) {
      p[i][I[i][j].id] = k;
      vis[i][k] = 1;
      ok &= 1;
      return;
    }
  }
  ok &= 0;
}

int main() {
  int n;
  while (scanf("%d", &n) && n) {
    ok = 1;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i) {
      scanf("%d%d%d%d", &I[0][i].l, &I[1][i].l, &I[0][i].r, &I[1][i].r);
      I[0][i].id = I[1][i].id = i;
    }
    std::sort(I[0], I[0] + n);
    std::sort(I[1], I[1] + n);
    for (int i = 0; i < n && ok; ++i) { place(0, i); place(1, i); }
    if (ok)
      for (int i = 0; i < n; ++i) printf("%d %d\n", p[0][i], p[1][i]);
    else puts("IMPOSSIBLE");
  }
  return 0;
}

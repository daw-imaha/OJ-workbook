#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1005;

struct Dot {
  int x, y;
} d1[maxn], d2[maxn];

int cmp1(Dot a, Dot b) { return a.x < b.x || a.x == b.x && a.y < b.y; }

int cmp2(Dot a, Dot b) { return a.x > b.x || a.x == b.x && a.y < b.y; }

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N, ok = 1;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d%d", &d1[i].x, &d1[i].y);
    memcpy(d2, d1, sizeof(Dot) * N);
    sort(d1, d1 + N, cmp1);
    sort(d2, d2 + N, cmp2);
    int dist = d1[0].x + d2[0].x;
    for (int i = 0; i < N; ++i)
      if (d1[i].y != d2[i].y || d1[i].x + d2[i].x != dist) { ok = 0; break; }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}

#include <cstdio>
#include <algorithm>
using namespace std;

struct Pallet {
  int w, h;
  bool operator<(const Pallet& rhs) const {
    return w < rhs.w || w == rhs.w && h < rhs.h;
  }
} p[6];

int is_box() {
  if (p[0].w != p[2].w || p[0].h != p[4].w || p[2].h != p[4].h) return 0;
  for (int i = 0; i < 6; i += 2)
    if (p[i].w != p[i + 1].w || p[i].h != p[i + 1].h) return 0;
  return 1;
}

int main() {
  while (~scanf("%d%d", &p[0].w, &p[0].h)) {
    for (int i = 1; i < 6; ++i)
      scanf("%d%d", &p[i].w, &p[i].h);
    for (int i = 0; i < 6; ++i)
      if (p[i].w > p[i].h) swap(p[i].w, p[i].h);
    sort(p, p + 6);
    puts(is_box() ? "POSSIBLE" : "IMPOSSIBLE");
  }
  return 0;
}

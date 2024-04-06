#include <cstdio>
#include <cstring>
#include <vector>

const int maxv = 1005;
int p[maxv], d[maxv], odd[maxv], V, E, T;
std::vector<int> r;

int find(int i) { return p[i] == i ? i : p[i] = find(p[i]); }

void init() {
  r.clear();
  memset(d, 0, sizeof(d));
  memset(odd, 0, sizeof(odd));
  for (int i = 0; i < maxv; ++i) p[i] = i;
}

void input() {
  int a, b;
  for (int i = 0; i < E; ++i) {
    scanf("%d%d", &a, &b);
    p[find(b)] = find(a);
    ++d[a]; ++d[b];
  }
}

int min_time() {
  int extra = 0;
  for (int i = 1; i <= V; ++i) {
    if (!d[i]) continue;
    if (d[i] & 1) ++odd[find(i)];  // odd degree
    if (i == p[i]) r.push_back(i); // root
  }
  for (int i = 0; i < r.size(); ++i)
    if (odd[r[i]] ^ 0 && odd[r[i]] ^ 2) extra += (odd[r[i]] - 2) / 2;
  return (r.size() - 1 + extra + E) * T;
}

int main() {
  int kase = 0;
  while (scanf("%d%d%d", &V, &E, &T) && V) {
    init();
    input();
    printf("Case %d: %d\n", ++kase, E ? min_time() : 0);
  }
  return 0;
}

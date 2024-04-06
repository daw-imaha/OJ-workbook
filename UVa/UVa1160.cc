#include <cstdio>

const int maxn = 1e5 + 5;
int p[maxn];

int find(int i) { return p[i] == i ? i : p[i] = find(p[i]); }

int main() {
  int a, b;
  while (~scanf("%d", &a)) {
    int refusal = 0;
    for (int i = 0; i < maxn; ++i) p[i] = i;
    while (a + 1) {
      scanf("%d", &b);
      a = find(a);
      b = find(b);
      p[a] == p[b] ? ++refusal : p[b] = a;
      scanf("%d", &a);
    }
    printf("%d\n", refusal);
  }
  return 0;
}

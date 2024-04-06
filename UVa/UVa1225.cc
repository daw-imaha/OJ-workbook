#include <cstdio>
#include <cstring>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N, a[10];
    scanf("%d", &N);
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= N; ++i) {
      int v = i;
      while (v) { ++a[v % 10]; v /= 10; }
    }
    for (int i = 0; i < 10; ++i) printf(i ? " %d" : "%d", a[i]);
    putchar('\n');
  }
  return 0;
}

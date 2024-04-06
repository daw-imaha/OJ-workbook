#include <cstdio>
#include <algorithm>

const int maxn = 1e5 + 5;
int a[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, l, i, j, q = 0;
    scanf("%d%d", &n, &l);
    for (i = 0; i < n; ++i) scanf("%d", &a[i]);
    std::sort(a, a + n);
    i = 0, j = n - 1;
    while (i <= j) {
      if (a[i] + a[j--] <= l) ++i;
      ++q;
    }
    printf("%d%s", q, T ? "\n\n" : "\n");
  }
  return 0;
}

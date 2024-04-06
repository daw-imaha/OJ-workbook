#include <cstdio>
#include <cstdlib>

int n, a[20];

int is_zero() {
  for (int i = 0; i < n; ++i)
    if (a[i]) return 0;
  return 1;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int num = 0, ok = 0;
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    while (num++ < 1000) {
      int old = a[0];
      for (int i = 0; i < n - 1; ++i)
        a[i] = abs(a[i] - a[i + 1]);
      a[n - 1] = abs(a[n - 1] - old);
      if (is_zero()) { ok = 1; break; }
    }
    puts(ok ? "ZERO" : "LOOP");
  }
  return 0;
}

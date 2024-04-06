#include <cstdio>
#include <cstdlib>

int main() {
  int n;
  while (scanf("%d", &n) && n) {
    int a, b = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a);
      b += a;
      ans += abs(b);
    }
    printf("%lld\n", ans);
  }
  return 0;
}

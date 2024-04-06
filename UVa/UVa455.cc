#include <cstdio>
#include <cstring>

int main() {
  int N;
  char s[85];
  scanf("%d", &N);
  while (N--) {
    scanf("%s", s);
    int n = strlen(s);
    for (int k = 1; k <= n; ++k) {
      if (n % k) continue;
      int ok = 1;
      for (int i = k; ok && i < n; ++i)
        if (s[i] != s[i % k]) ok = 0;
      if (ok) { printf("%d\n", k); break; }
    }
    if (N) putchar('\n');
  }
  return 0;
}

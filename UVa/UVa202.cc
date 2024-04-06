#include <cstdio>

const int maxn = 3005;
int q[maxn], r[maxn];

int main() {
  int a, b;
  while (~scanf("%d%d", &a, &b)) {
    int n = 0, ok = 1;
    printf("%d/%d = %d.", a, b, a / b);
    a %= b;
    while (ok) {
      a *= 10;
      int c = a / b;  // quotient
      a %= b;         // remainder
      for (int i = 0; i < n; ++i) {
        if (q[i] == c && r[i] == a) {
          for (int j = 0; j < i; ++j) printf("%d", q[j]);
          putchar('(');
          int len = n < 50 ? n : 50;
          for (int j = i; j < len; ++j) printf("%d", q[j]);
          if (n >= 50) printf("...");
          printf(")\n   %d = number of digits in repeating cycle\n\n", n - i);
          ok = 0;
          break;
        }
      }
      q[n] = c;
      r[n++] = a;
    }
  }
  return 0;
}

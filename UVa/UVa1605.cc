#include <cstdio>

const char *s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int n;

void build(int dir) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) putchar(s[dir ? i : j]);
    puts("");
  }
}

int main() {
  int kase = 0;
  while (~scanf("%d", &n)) {
    if (kase++) putchar('\n');
    printf("2 %d %d\n", n, n);
    build(0); puts(""); build(1);
  }
  return 0;
}

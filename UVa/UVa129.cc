#include <cstdio>

char s[85];
int n, L, cnt;

int dfs(int cur) {
  if (cnt++ == n) {
    for (int i = 0; i < cur; i++) {
      putchar(s[i]);
      if (!((i + 1) % 64) || i + 1 == cur) putchar('\n');
      else if (!((i + 1) % 4)) putchar(' ');
    }
    printf("%d\n", cur);
    return 1;
  } else for (int i = 0; i < L; i++) {
    bool ok = 1;
    s[cur] = 'A' + i;
    for (int j = 1; j * 2 <= cur + 1; j++) {
      bool equal = 1;
      for (int k = 0; k < j; k++)
        if (s[cur - k] != s[cur - j - k]) { equal = 0; break; }
      if (equal) { ok = 0; break; }
    }
    if (ok && dfs(cur + 1)) return 1;
  }
  return 0;
}

int main() {
  while (scanf("%d%d", &n, &L) && n) { cnt = 0; dfs(0); }
  return 0;
}

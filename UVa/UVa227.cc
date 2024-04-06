#include <cstdio>
#include <cstring>

const char *s = "ABRL";
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, 1, -1};

int main() {
  char a;
  int kase = 0;
  while ((a = getchar()) && a != 'Z') {
    int r, c, ok = 1;
    char p[5][5];
    p[0][0] = a;
    if (a == ' ') r = c = 0;
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j) {
        if (!i && !j) continue;
        p[i][j] = a = getchar();
        if (a == ' ') { r = i; c = j; }
      }
      getchar();
    }
    while ((a = getchar()) && a != '0') {
      if (a == '\n') continue;
      if (!strchr(s, a)) ok = 0;
      if (ok) {
        int i = strchr(s, a) - s;
        int tr = r + dr[i], tc = c + dc[i];
        if (tr < 0 || tr > 4 || tc < 0 || tc > 4) {
          while (a != '0') a = getchar();
          ok = 0;
          break;
        } else {
          p[r][c] = p[tr][tc];
          p[tr][tc] = ' ';
          r = tr;
          c = tc;
        }
      }
    }
    getchar();
    if (kase++) putchar('\n');
    printf("Puzzle #%d:\n", kase);
    if (ok) {
      for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) printf(j < 4 ? "%c " : "%c", p[i][j]);
        putchar('\n');
      }
    } else printf("This puzzle has no final configuration.\n");
  }
  return 0;
}

#include <cstdio>
#include <cstring>

char G[10][10];
int r, c, N[10][10];

void init() {
  int n = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (G[i][j] != '*' && (!i || !j || G[i][j-1] == '*' || G[i-1][j] == '*')) N[i][j] = ++n;
      else N[i][j] = G[i][j] == '*' ? -1 : 0;
    }
  }
}

void print_across() {
  for (int i = 0; i < r; ++i) {
    int j = 0;
    while (j < c) {
      if (N[i][j] > 0) {
        printf("%3d.", N[i][j]);
        while (j < c && N[i][j] != -1) putchar(G[i][j++]);
        putchar('\n');
      }
      ++j;
    }
  }
}

void print_down() {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (N[i][j] > 0 && (!i || N[i - 1][j] == -1)) {
        int k = i;
        printf("%3d.", N[k][j]);
        while (k < r && N[k][j] != -1) putchar(G[k++][j]);
        putchar('\n');
      }
    }
  }
}

int main() {
  int kase = 0;
  while (scanf("%d", &r) && r) {
    scanf("%d", &c);
    memset(G, 0, sizeof(G));
    memset(N, 0, sizeof(N));
    for (int i = 0; i < r; ++i) { scanf("%s", G[i]); getchar(); }
    init();
    if (kase) putchar('\n');
    printf("puzzle #%d:\nAcross\n", ++kase);
    print_across();
    printf("Down\n");
    print_down();
  }
  return 0;
}

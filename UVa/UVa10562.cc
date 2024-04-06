#include <cstdio>
#include <cstring>

const int maxn = 205;
char tree[maxn][maxn];

int printable(char c) { return c != '-' && c != '|' && c != ' ' && c != '#' && c != '\n'; }

void undraw(int r, int c) {
  printf("%c(", tree[r][c]);
  if (tree[r + 1][c] == '|') {
    int k = c, n = strlen(tree[r + 3]);
    while (k && tree[r + 2][k - 1] == '-') --k;
    while (k < n && tree[r + 2][k] != ' ') {
      if (printable(tree[r + 3][k])) undraw(r + 3, k);
      ++k;
    } 
  }
  putchar(')');
}

int main() {
  int T;
  scanf("%d", &T);
  getchar();
  while (T--) {
    int i = 0;
    memset(tree, 0, sizeof(tree));
    while (*fgets(tree[i++], maxn, stdin) != '#');
    int n = strlen(tree[0]);
    putchar('(');
    for (int i = 0; i < n; ++i)
      if (printable(tree[0][i])) { undraw(0, i); break; }
    puts(")");
  }
  return 0;
}

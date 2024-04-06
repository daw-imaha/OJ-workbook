#include <cstdio>
#include <cstring>

const int maxn = 30;
int lch[maxn], rch[maxn];
char preord[maxn], inord[maxn];

int build(int L1, int R1, int L2, int R2) {
  if (L1 > R1) return -1;
  int root = preord[L1] - 'A', p = L2;
  while (inord[p] - 'A' != root) ++p;
  int cnt = p - L2;
  lch[root] = build(L1 + 1, L1 + cnt, L2, p - 1);
  rch[root] = build(L1 + cnt + 1, R1, p + 1, R2);
  return root;
}

void post_order(int root) {
  if (root == -1) return;
  post_order(lch[root]);
  post_order(rch[root]);
  putchar(root + 'A');
}

int main() {
  while (scanf("%s%s", preord, inord) == 2) {
    int n = strlen(preord);
    post_order(build(0, n - 1, 0, n - 1));
    putchar('\n');
  }
  return 0;
}

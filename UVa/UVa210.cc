#include <cstdio>
#include <cstring>

const int maxn = 1005;
int var[26], n, t[5], Q, locked;
int rq[maxn], bq[maxn], f1, r1, f2, r2;
// rq: ready queue, f1: rq front, r1: rq rear
// bq: blocked queue, f2: bq front, r2: bq rear

struct Program {
  int cur;
  char st[30][10];
} p[maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    locked = 0;
    f1 = f2 = 1;
    r1 = r2 = 0;
    memset(p, 0, sizeof(p));
    memset(var, 0, sizeof(var));
    scanf("%d%d%d%d%d%d%d", &n, &t[0], &t[1], &t[2], &t[3], &t[4], &Q);
    for (int i = 0; i < n; ++i) {
      for (int j = 0;; ++j) {
        fgets(p[i].st[j], 10, stdin);
        if (p[i].st[j][2] == 'd') break;
      }
    }
    for (int i = 0; i < n; ++i) rq[++r1] = i;
    while (f1 <= r1) {
      int q = Q, i = rq[f1++];
      while (q > 0) {
        char *s = p[i].st[p[i].cur];
        if (s[2] == '=') {
          int v;
          char c;
          sscanf(s, "%c = %d", &c, &v);
          var[c - 'a'] = v;
          q -= t[0];
        } else if (s[0] == 'p') {
          printf("%d: %d\n", i + 1, var[s[6] - 'a']);
          q -= t[1];
        } else if (s[0] == 'l') {
          if (locked) {  // place to blocked queue
            bq[++r2] = i;
            break;
          }
          locked = 1;
          q -= t[2];
        } else if (s[0] == 'u') {
          if (f2 <= r2) rq[--f1] = bq[f2++];  // move to ready queue
          locked = 0;
          q -= t[3];
        } else if (s[0] == 'e') break;
        ++p[i].cur;
      }
      if (q <= 0) rq[++r1] = i;
    }
    if (T) putchar('\n');
  }
  return 0;
}

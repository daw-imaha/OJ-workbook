#include <cstdio>
#include <cstring>

const int maxn = 3e5 + 5;
const int maxl = 26;
const int MOD = 20071027;

char s1[maxn], s2[105];
int S, n, d[maxn];

struct Trie {
  int ch[maxn][maxl];
  int val[maxn];
  int sz;
  Trie() { sz = 1; memset(ch, 0, sizeof(ch)); }

  void clear() {
    sz = 1;
    memset(ch, 0, sizeof(ch));
    memset(val, 0, sizeof(val));
  };

  void insert() {
    int u = 0, m = strlen(s2);
    for (int i = 0; i < m; ++i) {
      int c = s2[i] - 'a';
      if (!ch[u][c]) { val[sz] = 0; ch[u][c] = sz++; }
      u = ch[u][c];
    }
    val[u] = 1;
  }

  void search(int p){
    int u = 0;
    for (int i = p; i < n; ++i) {
      int c = s1[i] - 'a';
      if (!ch[u][c]) break;
      if (val[ch[u][c]]) d[p] = (d[p] + d[i + 1]) % MOD;
      u = ch[u][c];
    }
  }
} T;

int main() {
  int kase = 0;
  while (~scanf("%s", s1)) {
    T.clear();
    n = strlen(s1);
    memset(d, 0, sizeof(d));
    d[n] = 1;
    scanf("%d", &S);
    for (int i = 0; i < S; ++i) { scanf("%s", s2); T.insert(); }
    for (int i = n - 1; i >= 0; --i) T.search(i);
    printf("Case %d: %d\n", ++kase, d[0]);
  }
  return 0;
}

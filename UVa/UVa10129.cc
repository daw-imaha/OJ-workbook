#include <cstdio>
#include <cstring>

char s[1005];
int p[26], d[26], vis[26];  // Union-Find Set

int find(int i) { return p[i] == i ? i : p[i] = find(p[i]); }

int euler() {
  int n1 = 0, n2 = 0;
  for (int i = 0; i < 26; ++i) {
    if (vis[i] && p[i] == i) ++n1;
    if (!d[i] || d[i] == -1 || d[i] == 1) ++n2;
  }
  return n1 == 1 && n2 == 26;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    memset(d, 0, sizeof(d));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < 26; ++i) p[i] = i;
    for (int i = 0; i < N; ++i) {
      scanf("%s", s);
      int u = s[0] - 'a', v = s[strlen(s) - 1] - 'a';
      vis[u] = vis[v] = 1;
      p[find(u)] = find(v);
      --d[u];
      ++d[v];
    }
    puts(euler() ? "Ordering is possible." : "The door cannot be opened.");
  }
  return 0;
}

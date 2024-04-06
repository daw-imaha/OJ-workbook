#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10005;
vector<int> G[maxn];
int n, m, k, c[maxn], d[maxn], vis[maxn];

void init_and_input() {
  k = 0;
  memset(c, 0, sizeof(c));
  memset(d, 0, sizeof(d));
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; ++i) G[i].clear();
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
    ++d[a]; ++d[b];
  }
  k = *max_element(d + 1, d + n + 1) | 1;
}

void dfs(int u) {
  for (int i = 0; i < G[u].size(); ++i) vis[c[G[u][i]]] = u;
  for (int i = 1; i <= k; ++i)
    if (vis[i] != u) { c[u] = i; break; }
  for (int i = 0; i < G[u].size(); ++i)
    if (!c[G[u][i]]) dfs(G[u][i]);
}

void print_ans() {
  printf("%d\n", k);
  for (int i = 1; i <= n; ++i) printf("%d\n", c[i]);
  putchar('\n');
}

int main() {
  while (~scanf("%d%d", &n, &m)) {
    init_and_input();
    dfs(1);
    print_ans();
  }
  return 0;
}

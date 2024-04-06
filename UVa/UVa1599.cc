#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;
const int maxn = 1e5 + 5;

struct Edge {
  int u, v, w;
  Edge(int a, int b, int c) : u(a), v(b), w(c) {}
};

vector<Edge> E;
vector<int> G[maxn], p;
int n, m, d[maxn], vis[maxn];

void rev_bfs() {
  memset(vis, 0, sizeof(vis));
  queue<int> q;
  q.push(n);
  vis[n] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < G[u].size(); ++i) {
      int e = G[u][i], v = E[e].u == u ? E[e].v : E[e].u;
      if (!vis[v]) {
        q.push(v);
        vis[v] = 1;
        d[v] = d[u] + 1;
      }
    }
  }
}

void bfs() {
  memset(vis, 0, sizeof(vis));
  vector<int> cur{1};
  vis[1] = 1;
  for (int i = 0; i < d[1]; ++i) {
    int min_color = INF;
    for (int j = 0; j < cur.size(); ++j) {
      int u = cur[j];
      for (int k = 0; k < G[u].size(); ++k) {
        int e = G[u][k], color = E[e].w;
        int v = E[e].u == u ? E[e].v : E[e].u;
        if (d[u] - d[v] == 1 && min_color > color) min_color = color;
      }
    }
    p.push_back(min_color);
    vector<int> next;
    for (int j = 0; j < cur.size(); ++j) {
      int u = cur[j];
      for (int k = 0; k < G[u].size(); ++k) {
        int e = G[u][k], color = E[e].w;
        int v = E[e].u == u ? E[e].v : E[e].u;
        if (!vis[v] && d[u] - d[v] == 1 && color == min_color) {
          vis[v] = 1;
          next.push_back(v);
        }
      }
    }
    cur = next;
  }
}

int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    E.clear();
    p.clear();
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= n; ++i) G[i].clear();
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      E.push_back(Edge(a, b, c));
      G[a].push_back(E.size() - 1);
      G[b].push_back(E.size() - 1);
    }
    rev_bfs();
    bfs();
    printf("%d\n", d[1]);
    for (int i = 0; i < p.size(); ++i) printf(i ? " %d" : "%d", p[i]);
    putchar('\n');
  }
  return 0;
}

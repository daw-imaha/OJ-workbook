#include <cstdio>
#include <cstring>
#include <queue>

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
int m, n, k, G[20][20], d[20][20][25];

struct Cell {
  int r, c, b;  // b: balance
  Cell(int r, int c, int b) : r(r), c(c), b(b) {}
};

Cell walk(Cell &u, int dir) {
  int x = u.r + dr[dir], y = u.c + dc[dir];
  return Cell(x, y, G[x][y] ? u.b - 1 : k);
}

bool inside(int r, int c) { return r >= 0 && r < m && c >= 0 && c < n; }

int bfs() {
  Cell o(0, 0, k);
  std::queue<Cell> q;
  q.push(o);
  d[0][0][k] = 0;
  while (!q.empty()) {
    Cell u = q.front();
    q.pop();
    if (u.r == m - 1 && u.c == n - 1) return d[u.r][u.c][u.b];
    for (int i = 0; i < 4; ++i) {
      Cell v = walk(u, i);
      if (inside(v.r, v.c) && v.b >= 0 && d[v.r][v.c][v.b] < 0) {
        d[v.r][v.c][v.b] = d[u.r][u.c][u.b] + 1;
        q.push(v);
      }
    }
  }
  return -1;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &m, &n, &k);
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) scanf("%d", &G[i][j]);
    memset(d, -1, sizeof(d));
    printf("%d\n", bfs());
  }
  return 0;
}

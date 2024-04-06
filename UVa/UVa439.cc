#include <cstdio>
#include <cstring>
#include <queue>

const int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dr[] = {2, 1, -1, -2, -2, -1, 1, 2};
int d[8][8];

struct Square {
  int c, r;
} a, b;

int bfs() {
  std::queue<Square> q;
  q.push(a);
  d[a.c][a.r] = 0;
  while (!q.empty()) {
    Square u = q.front();
    q.pop();
    if (u.c == b.c && u.r == b.r) return d[u.c][u.r];
    for (int i = 0; i < 8; ++i) {
      int x = u.c + dc[i], y = u.r + dr[i];
      if (d[x][y] < 0 && x >= 0 && x < 8 && y >= 0 && y < 8) {
        q.push(Square{x, y});
        d[x][y] = d[u.c][u.r] + 1;
      }
    }
  }
}

int main() {
  char s1[3], s2[3];
  while (~scanf("%s%s", s1, s2)) {
    memset(d, -1, sizeof(d));
    a = Square{s1[0] - 'a', s1[1] - '1'};
    b = Square{s2[0] - 'a', s2[1] - '1'};
    printf("To get from %s to %s takes %d knight moves.\n", s1, s2, bfs());
  }
  return 0;
}

#include <cstdio>
#include <cstring>

const int gdir[4][2] = {0, 1, 0, -1, -1, 0, 1, 0};
const int hdir[8][2] = {-2, -1, -2, 1, 2, -1, 2, 1, -1, -2, 1, -2, -1, 2, 1, 2};

struct Piece {
  char type;
  int r, c;
} p[10];
int N, r0, c0, board[11][10];

int legal(int r, int c, int G) {
  if (G) return r > 0 && r < 4 && c > 3 && c < 7;
  return r > 0 && r < 11 && c > 0 && c < 10;
}

int stat(int r, int c, int tr, int tc) {
  int dr = 0, dc = 0, cnt = -board[r][c], n;
  if (r == tr) { dc = c < tc ? 1 : -1; n = c < tc ? tc - c : c - tc; }
  else { dr = r < tr ? 1 : -1; n = r < tr ? tr - r : r - tr; }
  for (int i = 0; i < n; ++i) {
    if (board[r][c]) ++cnt;
    r += dr; c += dc;
  }
  return cnt;
}

int main() {
  while (scanf("%d %d %d", &N, &r0, &c0) && N) {
    int ok;
    memset(p, 0, sizeof(p));
    memset(board, 0, sizeof(board));
    for (int i = 0; i < N; ++i) {
      scanf("\n%c%d%d", &p[i].type, &p[i].r, &p[i].c);
      board[p[i].r][p[i].c] = 1;
    }
    for (int i = 0; i < N; ++i)
      if (p[i].type == 'G' && p[i].c == c0 && !stat(r0, c0, p[i].r, p[i].c)) { ok = 0; goto checkmate; }
    for (int i = 0; i < 4; ++i) {
      int r1 = r0 + gdir[i][0], c1 = c0 + gdir[i][1];
      if (legal(r1, c1, 1)) {
        ok = 0;
        for (int j = 0; j < N; ++j) {
          int pr = p[j].r, pc = p[j].c;
          if (p[j].type == 'G' && pc == c1 && !stat(r1, c1, pr, pc)) ok = 1;
          else if (p[j].type == 'R' && (pr == r1 || pc == c1) && !stat(r1, c1, pr, pc)) ok = 1;
          else if (p[j].type == 'C' && (pr == r1 || pc == c1) && stat(r1, c1, pr, pc) == 1) ok = 1;
          else if (p[j].type == 'H') {
            for (int k = 0; k < 8; ++k) {
              if (board[pr + hdir[k][0] / 2][pc + hdir[k][1] / 2]) continue;
              int hr = pr + hdir[k][0], hc = pc + hdir[k][1];
              if (legal(hr, hc, 0) && hr == r1 && hc == c1) { ok = 1; break; }
            }
          }
          if (ok) break;
        }
        if (!ok) break;
      }
    }
    checkmate: puts(ok ? "YES" : "NO");
  }
  return 0;
}

#include <cstdio>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxh = 205;
const int maxw = 205;
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};
const char *code = "WAKJSD";
const char *bin[] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

int H, W, hole_num;
char pic[maxh][maxw], color[maxh][maxw];

void decode(int r, int c, char ch) {
  int dec = isdigit(ch) ? ch - '0' : ch - 'a' + 10;
  for (int i = 0; i < 4; ++i)
    pic[r][c + i] = bin[dec][i] - '0';
}

void fill(int r, int c, int id) {
  if (pic[r][c] || color[r][c] || r < 0 || r >= H || c < 0 || c >= W) return;
  color[r][c] = id;
  for (int i = 0; i < 4; ++i)
    fill(r + dr[i], c + dc[i], id);
}

void bound(int r, int c) {
  if (color[r][c] || r < 0 || r >= H || c < 0 || c >= W) return;
  if (pic[r][c]) {
    color[r][c] = 1;
    for (int i = 0; i < 4; ++i)
      bound(r + dr[i], c + dc[i]);
  } else {
    ++hole_num;
    fill(r, c, 2);
  }
}

int main() {
  int kase = 0;
  while (~scanf("%d%d", &H, &W) && H) {
    string ans;
    memset(pic, 0, sizeof(pic));
    memset(color, 0, sizeof(color));
    for (int i = 0; i < H; ++i) {
      char s[maxw];
      scanf("%s", s);
      for (int j = 0; j < W; ++j)
        decode(i + 1, j * 4 + 1, s[j]);
    }
    H += 2;
    W = 4 * W + 2;
    fill(0, 0, -1);
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (pic[i][j] && !color[i][j]) {
          hole_num = 0;
          bound(i, j);
          ans += code[hole_num];
        }
      }
    }
    sort(ans.begin(), ans.end());
    printf("Case %d: %s\n", ++kase, ans.c_str());
  }
  return 0;
}

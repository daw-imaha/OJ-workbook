#include <cstdio>
#include <cstring>

char s[512];
int X, img[32][32];

void draw(int& p, int r, int c, int w) {
  char node = s[p++];
  if (node == 'p') {
    draw(p, r,         c + w / 2, w / 2);
    draw(p, r,         c,         w / 2);
    draw(p, r + w / 2, c,         w / 2);
    draw(p, r + w / 2, c + w / 2, w / 2);
  }
  else if (node == 'f') {
    for (int i = r; i < r + w; i++)
      for (int j = c; j < c + w; j++)
        if (img[i][j] == 0) { img[i][j] = 1; X++; }
  }
}

int main() {
  int N;
  scanf("%d", &N);
  while (N--) {
    X = 0;
    memset(img, 0, sizeof(img));
    for (int i = 0; i < 2; i++) {
      int p = 0;
      scanf("%s", s);
      draw(p, 0, 0, 32);
    }
    printf("There are %d black pixels.\n", X);
  }
  return 0;
}

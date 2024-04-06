#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int n, kase = 0;
char img[70][70];
vector<int> path;

int node_color(int r, int c, int w) {
  int color = 0;
  for (int i = r; i < r + w; i++)
    for (int j = c; j < c + w; j++)
      color |= img[i][j] == '0' ? 1 : 2;
  return color;
}

/*
 * d: depth
 * b: branch
 */
void img2path(int r, int c, int w, int d, int b, int num) {
  int color = node_color(r, c, w);
  if (color < 2) return;
  num += b * (int)pow(5, d - 1);
  if (color == 2) {
    path.push_back(num);
    return;
  }
  ++d; // next level
  img2path(r,         c,         w / 2, d, 1, num);
  img2path(r,         c + w / 2, w / 2, d, 2, num);
  img2path(r + w / 2, c,         w / 2, d, 3, num);
  img2path(r + w / 2, c + w / 2, w / 2, d, 4, num);
}

void path2img(int r, int c, int w, int num) {
  switch (num % 5) {
    case 0: {
      for (int i = r; i < r + w; i++)
        for (int j = c; j < c + w; j++) img[i][j] = '*';
      return;
    }
    case 1: path2img(r,         c,         w / 2, num / 5); break;
    case 2: path2img(r,         c + w / 2, w / 2, num / 5); break;
    case 3: path2img(r + w / 2, c,         w / 2, num / 5); break;
    case 4: path2img(r + w / 2, c + w / 2, w / 2, num / 5); break;
  }
}

void print_ans() {
  if (kase) putchar('\n');
  printf("Image %d", ++kase);
  if (n > 0) {
    sort(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++)
      printf(i % 12 ? " %d" : "\n%d", path[i]);
    printf("\nTotal number of black nodes = %d\n", path.size()); 
  } else {
    putchar('\n');
    for (int i = 0; i < -n; i++) {
      for (int j = 0; j < -n; j++)
        putchar(img[i][j] == '*' ? '*' : '.');
      putchar('\n');
    }
  }
}

void input_and_convert() {
  path.clear();
  memset(img, 0, sizeof(img));
  if (n > 0) {
    for (int i = 0; i < n; i++) scanf("%s", img[i]);
    img2path(0, 0, n, 0, 0, 0);
  } else {
    int num;
    while (scanf("%d", &num) && num != -1)
      path2img(0, 0, -n, num);
  }
}

int main() {
  while (scanf("%d", &n) && n) {
    input_and_convert();
    print_ans();
  }
  return 0;
}

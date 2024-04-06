#include <cstdio>
#include <cstring>
#include <algorithm>

const int mask_table[] = {0, 128, 192, 224, 240, 248, 252, 254, 255};
int ip[4][1005], addr[4], mask[4];

int LCP(int a, int b) {  // longest common prefix
  int n = 0;
  for (int i = 0; i < 8; ++i) {
    if ((a & 128) ^ (b & 128)) break;
    a <<= 1;
    b <<= 1;
    ++n;
  }
  return n;
}

int main() {
  int m;
  while (~scanf("%d", &m)) {
    memset(mask, 0, sizeof(mask));
    memset(addr, 0, sizeof(addr));
    for (int i = 0; i < m; ++i)
      scanf("%d.%d.%d.%d", &ip[0][i], &ip[1][i], &ip[2][i], &ip[3][i]);
    for (int i = 0; i < 4; ++i) {
      std::sort(ip[i], ip[i] + m);
      mask[i] = mask_table[LCP(ip[i][0], ip[i][m - 1])];
      addr[i] = mask[i] & ip[i][0];
      if (mask[i] ^ 255) break;
    }
    printf("%d.%d.%d.%d\n", addr[0], addr[1], addr[2], addr[3]);
    printf("%d.%d.%d.%d\n", mask[0], mask[1], mask[2], mask[3]);
  }
  return 0;
}

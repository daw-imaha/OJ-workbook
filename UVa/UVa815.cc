#include <cstdio>
#include <algorithm>

int m, n, H[1005];
double v, k, wl; // v: volume, wl: water level

int main() {
  int kase = 0;
  while (scanf("%d%d", &m, &n) && m) {
    n *= m;
    for (int i = 0; i < n; ++i) scanf("%d", &H[i]);
    scanf("%lf", &v);
    v /= 100; // volume -> elevation
    std::sort(H, H + n);
    H[n] = 0x7fffffff;
    for (int i = 1; i <= n; ++i) {
      v += H[i - 1];
      wl = v / i;
      if (wl < H[i]) { k = i; break; }
    }
    printf("Region %d\nWater level is %.2f meters.\n", ++kase, wl);
    printf("%.2f percent of the region is under water.\n\n", k * 100 / n); 
  }
  return 0;
}

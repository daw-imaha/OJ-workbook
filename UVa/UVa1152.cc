#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 4005;
int A[maxn], B[maxn], C[maxn], D[maxn], s[maxn * maxn];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, cnt = 0, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        s[cnt++] = A[i] + B[j];
    sort(s, s + cnt);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        ans += upper_bound(s, s+cnt, -C[i]-D[j]) - lower_bound(s, s+cnt, -C[i]-D[j]);
    printf("%d%s", ans, T ? "\n\n" : "\n");
  }
  return 0;
}

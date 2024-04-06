#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 2e4 + 5;
int A[maxn], B[maxn];

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) && n) {
    int wage = 0, cur = 0;
    for (int i = 0; i < n; ++i) scanf("%d", &A[i]);
    for (int i = 0; i < m; ++i) scanf("%d", &B[i]);
    sort(A, A + n);
    sort(B, B + m);
    for (int i = 0; i < m; ++i) {
      if (A[cur] <= B[i]) {
        wage += B[i];
        if (++cur == n) break;
      }
    }
    if (cur < n) puts("Loowater is doomed!");
    else printf("%d\n", wage);
  }
  return 0;
}

#include <cstdio>
#include <cstring>

bool vis[20], isp[35];
int A[20]{1}, n, kase = 0;

bool is_prime(int m) {
  for (int i = 2; i <= m / 2; i++)
    if (!(m % i)) return 0;
  return 1;
}

void dfs(int cur) {
  if (cur == n && isp[A[0] + A[n - 1]]) {
    for (int i = 0; i < n; i++)
      printf(i ? " %d" : "%d", A[i]);
    putchar('\n');
  } else for (int i = 2; i <= n; i++) {
    if (!vis[i] && isp[A[cur - 1] + i]) {
      A[cur] = i;
      vis[i] = 1;
      dfs(cur + 1);
      vis[i] = 0;
    }
  }
}

int main() {
  for (int i = 2; i < 35; i++) isp[i] = is_prime(i);
  while (~scanf("%d", &n)) {
    if (kase) putchar('\n');
    memset(vis, 0, sizeof(vis));
    printf("Case %d:\n", ++kase);
    dfs(1);
  }
  return 0;
}

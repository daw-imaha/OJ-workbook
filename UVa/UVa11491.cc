#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 5;
char s[maxn];
int N, D;

int main() {
  while (scanf("%d%d", &N, &D) && N) {
    int k = 0;
    char c = getchar();
    memset(s, 0, sizeof(s));
    for (int i = 0; i < N; ++i) {
      c = getchar();
      while (k && s[k-1] < c && i-k < D) --k;
      if (k < N - D) s[k++] = c;
    }
    puts(s);
  }
  return 0;
}

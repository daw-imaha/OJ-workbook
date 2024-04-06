#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn = 105;

int n1[26], n2[26];
char s1[maxn], s2[maxn];

int main() {
  while (~scanf("%s%s", s1, s2)) {
    memset(n1, 0, sizeof(n1));
    memset(n2, 0, sizeof(n2));
    int n = strlen(s1), ok = 1;
    for (int i = 0; i < n; ++i) {
      ++n1[s1[i] - 'A'];
      ++n2[s2[i] - 'A'];
    }
    std::sort(n1, n1 + 26);
    std::sort(n2, n2 + 26);
    for (int i = 0; i < 26; ++i)
      if (n1[i] ^ n2[i]) { ok = 0; break; }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}

#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 5;
char s[maxn], t[maxn];

int main() {
  while (~scanf("%s%s", s, t)) {
    int i = 0, n = strlen(t);
    for (int j = 0; j < n; ++j)
      if (t[j] == s[i]) ++i;
    puts(i == strlen(s) ? "Yes" : "No");
  }
  return 0;
}

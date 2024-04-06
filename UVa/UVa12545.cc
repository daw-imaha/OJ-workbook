#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxl = 105;
char S[maxl], T[maxl];

int main() {
  int C, kase = 0;
  scanf("%d", &C);
  while (C--) {
    scanf("%s%s", S, T);
    int n = strlen(S), a1 = 0, a2 = 0, a3 = 0;
    for (int i = 0; i < n; ++i) {
      if (S[i] != '?') a1 += S[i] - '0';
      a2 += T[i] - '0';
    }
    printf("Case %d: ", ++kase);
    if (a1 > a2) { puts("-1"); continue; }
    a1 = a2 = 0;
    for (int i = 0; i < n; ++i) {
      if (S[i] == '1' && T[i] == '0') ++a1;
      else if (S[i] == '0' && T[i] == '1') ++a2;
      else if (S[i] == '?') ++a3;
    }
    printf("%d\n", std::max(a1, a2) + a3);
  }
  return 0;
}

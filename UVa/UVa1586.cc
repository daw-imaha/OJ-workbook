#include <cstdio>
#include <cctype>
#include <cstring>
#include <unordered_map>

std::unordered_map<char, double> wt{{'C', 12.01}, {'H', 1.008}, {'O', 16.00}, {'N', 14.01}};

int main() {
  int T;
  char s[85];
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    double ans = .0;
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
      if (isdigit(s[i])) continue;
      if (!isdigit(s[i + 1])) ans += wt[s[i]];
      else ans += wt[s[i]] * (isdigit(s[i+2]) ? (s[i+1]-'0')*10 + s[i+2]-'0' : s[i+1]-'0');
    }
    printf("%.3f\n", ans);
  }
  return 0;
}

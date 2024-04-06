#include <cstdio>
#include <cstring>

int m, n;
char DNA[55][1005];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int err = 0;
    char ans[1005]{};
    scanf("%d%d", &m, &n);
    memset(DNA, 0, sizeof(DNA));
    for (int i = 0; i < m; ++i) scanf("%s", DNA[i]);
    for (int i = 0; i < n; ++i) {
      int num[26]{}, k = 0;
      for (int j = 0; j < m; ++j) ++num[DNA[j][i] - 'A'];
      for (int j = 0; j < 26; ++j)
        if (num[j] > num[k]) k = j;
      ans[i] = 'A' + k;
      err += m - num[k];
    }
    printf("%s\n%d\n", ans, err);
  }
  return 0;
}

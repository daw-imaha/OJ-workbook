#include <cstdio>
#include <cstring>
#include <cmath>

int n;
char morse_code[128][10], context[105][15], morse_word[105][65], ans[15];

void match(char *s) {
  int m = 0;
  for (int i = 0; i < n; ++i) {
    if (strcmp(s, morse_word[i])) continue;
    if (!m) strcpy(ans, context[i]);
    ++m;
  }
  if (m > 1) strcat(ans, "!");
  else if (!m) {
    int min_diff = 100;
    int l1 = strlen(s);
    for (int i = 0; i < n; ++i) {
      int l2 = strlen(morse_word[i]);
      if (!strncmp(morse_word[i], s, l1) || !strncmp(s, morse_word[i], l2)) {
        int diff = abs(l1 - l2);
        if (min_diff >= diff) {
          min_diff = diff;
          strcpy(ans, context[i]);
        }
      }
    }
    strcat(ans, "?");
  }
}

int main() {
  char c, s1[15], s2[65];
  while (scanf("%s", &c) && c != '*')
    scanf("%s", morse_code[c]);
  for (n = 0; scanf("%s", s1) && strcmp(s1, "*"); ++n) {
    strcpy(context[n], s1);
    memset(s2, 0, sizeof(s2));
    for (int i = 0; i < strlen(s1); ++i)
      strcat(s2, morse_code[s1[i]]);
    strcpy(morse_word[n], s2);
  }
  while (scanf("%s", s2) && strcmp(s2, "*")) {
    match(s2);
    printf("%s\n", ans);
  }
  return 0;
}

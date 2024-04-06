#include <cstdio>
#include <cstring>
const int maxn = 100;

int left, chance;
char s[maxn], s2[maxn];
int win, lose;
int guessed[256];

void guess(char c) {
  int bad = 1;
  for (int i = 0; i < strlen(s); ++i)
    if (s[i] == c) { s[i] = ' '; --left; bad = 0; }
  if (bad) --chance;
  if (!left) win = 1;
  if (!chance) lose = 1;
}

int main() {
  int rnd;
  while (scanf("%d%s%s", &rnd, s, s2) && rnd != -1) {
    printf("Round %d\n", rnd);
    win = lose = 0;
    left = strlen(s);
    chance = 7;
    memset(guessed, 0, sizeof(guessed));
    for (int i = 0; i < strlen(s2); ++i) {
      if (!guessed[s2[i]]) {
        guess(s2[i]);
        guessed[s2[i]] = 1;
        if (win || lose) break;
      }
    }
    if (win) printf("You win.\n");
    else if (lose) printf("You lose.\n");
    else printf("You chickened out.\n");
  }
  return 0;
}

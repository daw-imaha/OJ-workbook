#include <cstdio>
#include <cstring>

const char *s = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main() {
  char c;
  while (~(c = getchar()))
    putchar(c == ' ' || c == '\n' ? c : s[strchr(s, c)-s-1]);
  return 0;
}

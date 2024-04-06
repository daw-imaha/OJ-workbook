#include <cstdio>

int main() {
  int T;
  scanf("%d", &T);
  char c = getchar();
  while (T--) {
    int a = 0, b = 0;
    while ((c = getchar()) && c ^ '\n') c == 'O' ? b += ++a : a = 0;
    printf("%d\n", b);
  }
  return 0;
}

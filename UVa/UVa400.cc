#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string F[105];
int N, R, C, L;

void print(char c, int len) {
  for (int i = 0; i < len; ++i) putchar(c);
}

int main() {
  while (cin >> N) {
    L = 0;
    for (int i = 0; i < N; ++i) {
      cin >> F[i];
      L = max(L, (int)F[i].size());
    }
    sort(F, F + N);
    C = 62 / (L + 2);
    R = (N - 1) / C + 1;
    print('-', 60);
    putchar('\n');
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        int k = i + j * R;
        if (k < N) { cout << F[k]; print(' ', (k+R < N ? L+2 : L) - F[k].size()); }
        else break;
      }
      putchar('\n');
    }
  }
  return 0;
}

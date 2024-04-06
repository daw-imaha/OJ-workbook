#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int n, a[35];

void flip(int p) {
  printf("%d ", n - p);
  for (int i = 0; i < p - i; ++i) swap(a[i], a[p - i]);
}

int main() {
  string s;
  while (getline(cin, s)) {
    n = 0;
    cout << s << '\n';
    stringstream ss(s);
    while (ss >> a[n]) ++n;
    for (int i = n - 1; i; --i) {
      int A = a[i], p = i;
      for (int j = i - 1; j >= 0; --j)
        if (a[j] > A) { A = a[j]; p = j; }
      if (p == i) continue;
      if (p) flip(p);
      flip(i);
    }
    puts("0");
  }
  return 0;
}

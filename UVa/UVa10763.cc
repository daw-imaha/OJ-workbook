#include <cstdio>
#include <unordered_map>

int main() {
  int n;
  while (scanf("%d", &n) && n) {
    int A, B, ok = 1;
    std::unordered_map<int, int> num;
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &A, &B);
      --num[A];
      ++num[B];
    }
    for (auto& p : num)
      if (p.second) { ok = 0; break; }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}

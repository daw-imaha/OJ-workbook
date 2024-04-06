#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int n, m, k, v;
map<int, vector<int>> a;

int main() {
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &v);
      if (!a.count(v)) a[v] = vector<int>();
      a[v].push_back(i);
    }
    while (m--) {
      scanf("%d%d", &k, &v);
      printf("%d\n", !a.count(v) || k > a[v].size() ? 0 : a[v][k - 1]);
    }
  }
  return 0;
}

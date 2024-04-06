#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int n;
  while (scanf("%d", &n) && n) {
    queue<int> q;
    vector<int> v;
    for (int i = 1; i <= n; ++i) q.push(i);
    while (q.size() > 1) {
      v.push_back(q.front());
      q.pop();
      q.push(q.front());
      q.pop();
    }
    printf("Discarded cards:");
    for (int i = 0; i < v.size(); ++i)
      printf(i < v.size() - 1 ? " %d," : " %d", v[i]);
    printf("\nRemaining card: %d\n", q.front());
  }
  return 0;
}

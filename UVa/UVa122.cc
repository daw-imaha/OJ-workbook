#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int root = 1;
int val[260], left[260], right[260], cnt;
bool have_value[260], failed;
vector<int> ans;

void newtree() {
  left[root] = right[root] = 0;
  have_value[root] = false;
  cnt = root;
}

int newnode() {
  int u = ++cnt;
  left[u] = right[u] = 0;
  have_value[u] = false;
  return u;
}

void addnode(int v, char *s) {
  int n = strlen(s);
  int u = root;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') {
      if (!left[u]) left[u] = newnode();
      u = left[u];
    } else if (s[i] == 'R') {
      if (!right[u]) right[u] = newnode();
      u = right[u];
    }
  }
  if (have_value[u]) failed = true;
  val[u] = v;
  have_value[u] = true;
}

bool read_input() {
  failed = false;
  newtree();
  for (;;) {
    char s[270];
    if (scanf("%s", s) != 1) return false;
    if (!strcmp(s, "()")) break;
    int v;
    sscanf(&s[1], "%d", &v);
    addnode(v, strchr(s, ',') + 1);
  }
  return true;
}

bool bfs() {
  ans.clear();
  queue<int> q;
  q.push(root);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (!have_value[u]) return false;
    ans.push_back(val[u]);
    if (left[u]) q.push(left[u]);
    if (right[u]) q.push(right[u]);
  }
  return true;
}

int main() {
  while (read_input()) {
    if (failed || !bfs()) printf("not complete");
    else for (int i = 0; i < ans.size(); ++i) printf(i ? " %d" : "%d", ans[i]);
    putchar('\n');
  }
  return 0;
}

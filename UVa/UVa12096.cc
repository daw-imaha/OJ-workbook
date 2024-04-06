#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

typedef set<int> Set;
map<Set, int> IDcache;
vector<Set> Setcache;

int ID(Set x) {
  if (IDcache.count(x)) return IDcache[x];
  Setcache.push_back(x);
  return IDcache[x] = Setcache.size() - 1;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    stack<int> s;
    cin >> N;
    for (int i = 0; i < N; ++i) {
      string cmd;
      cin >> cmd;
      if (cmd[0] == 'P') s.push(ID(Set()));
      else if (cmd[0] == 'D') s.push(s.top());
      else {
        Set x1 = Setcache[s.top()]; s.pop();
        Set x2 = Setcache[s.top()]; s.pop();
        Set x;
        if (cmd[0] == 'U') set_union(ALL(x1), ALL(x2), INS(x));
        if (cmd[0] == 'I') set_intersection(ALL(x1), ALL(x2), INS(x));
        if (cmd[0] == 'A') { x = x2; x.insert(ID(x1));}
        s.push(ID(x));
      }
      cout << Setcache[s.top()].size() << '\n';
    }
    cout << "***\n";
  }
  return 0;
}

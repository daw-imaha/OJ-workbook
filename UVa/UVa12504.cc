#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>
using namespace std;

const string prefix = "+-*";
map<string, string> dict[2];
set<string> ans[3];

void find_out() {
  for (auto& p : dict[0]) {
    string key = p.first;
    if (dict[1].count(key)) {
      if (dict[0][key] != dict[1][key]) ans[2].insert(key);
      dict[1].erase(key);
    } else ans[1].insert(key);
  }
  for (auto& p : dict[1]) ans[0].insert(p.first);
}

void print_ans() {
  int changed = 0;
  for (int i = 0; i < 3; ++i) {
    if (ans[i].empty()) continue;
    changed = 1;
    cout << prefix[i];
    for (auto& k : ans[i]) cout << k << (k == *ans[i].rbegin() ? '\n' : ',');
  }
  if (!changed) cout << "No changes\n";
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    dict[0].clear();
    dict[1].clear();
    for (int i = 0; i < 3; ++i) ans[i].clear();
    for (int i = 0; i < 2; ++i) {
      string s, key, val;
      cin >> s;
      for (auto& c : s)
        if (!isalnum(c)) c = ' ';
      stringstream ss(s);
      while (ss >> key >> val) dict[i][key] = val;
    }
    find_out();
    print_ans();
    putchar('\n');
  }
  return 0;
}

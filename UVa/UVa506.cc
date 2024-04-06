#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

const int maxn = 1e4 + 5;

int status[maxn];
vector<string> name;
map<string, int> name2id;
vector<int> depend[maxn], depend2[maxn], installed;

int ID(const string& s) {
  if (!name2id.count(s)) {
    name2id[s] = name2id.size();
    name.push_back(s);
  }
  return name2id[s];
}

void install(int item, int level) {
  if (!status[item]) {
    for (int i = 0; i < depend[item].size(); ++i) install(depend[item][i], 2);
    status[item] = level;
    installed.push_back(item);
    cout << "   Installing " << name[item] << '\n';
  }
}

int needed(int item) {
  for (int i = 0; i < depend2[item].size(); ++i)
    if (status[depend2[item][i]]) return 1;
  return 0;
}

void remove(int item, bool top) {
  if ((top || status[item] == 2) && !needed(item)) {
    status[item] = 0;
    cout << "   Removing " << name[item] << '\n';
    installed.erase(remove(installed.begin(), installed.end(), item), installed.end());
    for (int i = 0; i < depend[item].size(); ++i) remove(depend[item][i], false);
  }
}

void list() {
  for (int i = 0; i < installed.size(); ++i)
    cout << "   " << name[installed[i]] << '\n';
}

int main() {
  string s;
  while (getline(cin, s)) {
    cout << s << '\n';
    if (s[0] == 'E') break;
    string item1, item2;
    stringstream ss(s); ss >> s;
    if (s[0] == 'L') list();
    else {
      ss >> item1;
      int i1 = ID(item1);
      if (s[0] == 'D') {
        while (ss >> item2) {
          int i2 = ID(item2);
          depend[i1].push_back(i2);
          depend2[i2].push_back(i1);
        }
      }
      else if (s[0] == 'I') {
        if (status[i1]) cout << "   " << name[i1] << " is already installed.\n";
        else install(i1, 1);
      }
      else if (s[0] == 'R') {
        if (!status[i1]) cout << "   " << name[i1] << " is not installed.\n";
        else if (needed(i1)) cout << "   " << name[i1] << " is still needed.\n"; 
        else remove(i1, true);
      }
    }
  }
  return 0;
}

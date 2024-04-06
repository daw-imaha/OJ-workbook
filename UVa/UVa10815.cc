#include <iostream>
#include <sstream>
#include <string>
#include <set>
using namespace std;

int main() {
  string s;
  stringstream ss;
  set<string> dict;
  while (getline(cin, s)) {
    for (auto& c : s) {
      if (isalpha(c)) c = tolower(c);
      else c = ' ';
    }
    ss << s;
    while (ss >> s) dict.insert(s);
    ss.clear();
  }
  for (auto& word : dict) cout << word << '\n';
  return 0;
}

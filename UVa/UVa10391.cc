#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
  string s;
  set<string> dict;
  while (cin >> s) dict.insert(s);
  for (auto& word : dict) {
    for (int i = 1; i < word.size(); ++i) {
      if (dict.count(word.substr(0, i)) && dict.count(word.substr(i))) {
        cout << word << '\n';
        break;
      }
    }
  }
  return 0;
}

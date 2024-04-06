#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int p[185];
vector<string> code[1005];

void print(const string &s, int len, char c) {
  cout << s;
  for (int i = 0; i < len - s.size(); ++i) putchar(c);
}

int main() {
  string s;
  int n1 = 0;
  while (getline(cin, s)) {
    int i = 0;
    stringstream ss(s);
    while (ss >> s) {
      code[n1].push_back(s);
      p[i] = max(p[i], (int)s.size());
      ++i;
    }
    ++n1;
  }
  for (int i = 0; i < n1; ++i) {
    int n2 = code[i].size();
    for (int j = 0; j < n2; ++j)
      print(code[i][j], j==n2-1 ? code[i][j].size() : p[j]+1, ' ');
    putchar('\n');
  }
  return 0;
}

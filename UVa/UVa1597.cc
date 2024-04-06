#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <string>
#include <regex>
#include <map>
#include <set>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

vector<string> doc[100];
map<string, set<int>> D;
map<string, set<pair<int, int>>> V;

void print_line(set<pair<int, int>>& ans) {
  if (ans.empty()) { puts("Sorry, I found nothing."); return; }
  int pre = ans.begin()->first; 
  for (auto& DID : ans) {
    if (DID.first != pre) puts("----------");
    cout << doc[DID.first][DID.second] << '\n';
    pre = DID.first;
  }
}

int main() {
  int N, M;
  stringstream ss;
  string s, term[2];
  cin >> N; getchar();
  for (int i = 0; i < N; i++) {
    int j = 0; // line number
    while (getline(cin, s) && s[0] != '*') {
      doc[i].push_back(s);
      ss << regex_replace(s, regex("[^a-zA-Z]"), " ");
      while (ss >> s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        V[s].insert({i, j});
        D[s].insert(i);
      }
      j++;
      ss.clear();
    }
  }
  cin >> M; getchar();
  while (M--) {
    getline(cin, s);
    if (s[0] == 'N') {
      int kase = 0;
      term[0] = s.substr(4);
      if (D[term[0]].size() == N) {
        puts("Sorry, I found nothing.");
        goto end;
      }
      for (int i = 0; i < N; i++) {
        if (D[term[0]].count(i)) continue;
        if (kase++) puts("----------");
        for (auto& line : doc[i]) cout << line << '\n';
      }
    } else {
      int op = 0;
      op |= s.find("AND") == -1 ? 0 : 1;
      op |= s.find("OR")  == -1 ? 0 : 2;
      if (!op) print_line(V[s]);
      else {
        set<int> dns; // document number set
        set<pair<int, int>> ans;
        term[0] = s.substr(0, s.find(' '));
	term[1] = s.substr(s.rfind(' ') + 1);
        op == 1 ? set_intersection(ALL(D[term[0]]), ALL(D[term[1]]), INS(dns))
                : set_union(ALL(D[term[0]]), ALL(D[term[1]]), INS(dns));
        for (int n : dns) {
          for (int i = 0; i < 2; i++)
            for (auto& DID : V[term[i]])
	      if (DID.first == n) ans.insert(DID);
	}
        print_line(ans);
      }
    }
end:
    puts("==========");
  }
  return 0;
}

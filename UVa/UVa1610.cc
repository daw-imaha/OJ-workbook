#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  while (cin >> n && n) {
    string S;
    vector<string> D;
    for (int i = 0; i < n; ++i) { cin >> S; D.push_back(S); }
    sort(D.begin(), D.end());
    S.clear();
    int l = n / 2 - 1, r = l + 1, sz = D[l].size();
    for (int i = 0; i < sz; ++i) {
      S += i < sz - 1 ? D[l][i] + 1 : D[l][i];
      if (S[i] != '[' && S < D[r]) break;
      --S[i];
    }
    cout << S << '\n';
  }
  return 0;
}

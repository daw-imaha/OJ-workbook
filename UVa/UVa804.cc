#include <cstdio>
#include <vector>

const int maxn = 105;
int NP, NT, NF, p[maxn];

int main() {
  int kase = 0;
  while (scanf("%d", &NP) && NP) {
    int dead = 0, num = 0;
    std::vector<int> ip[maxn], op[maxn];               // ip: input place, op: output place
    for (int i = 1; i <= NP; ++i) scanf("%d", &p[i]);  // begin from 1
    scanf("%d", &NT);
    for (int i = 0; i < NT; ++i) {
      int j;
      while (scanf("%d", &j) && j)
        j < 0 ? ip[i].push_back(-j) : op[i].push_back(j);
    }
    scanf("%d", &NF);
    for (int i = 0; i < NF; ++i, ++num) {
      dead = 1;
      for (int j = 0; j < NT && dead; ++j) {
        int fire = 1;
        for (int k = 0; k < ip[j].size() && fire; ++k) {
          if (--p[ip[j][k]] < 0) {
            while (k >= 0) ++p[ip[j][k--]];
            fire = 0;
          }
        }
        if (fire) {
          for (int k = 0; k < op[j].size(); ++k) ++p[op[j][k]];
          dead = 0;
        }
      }
      if (dead) break;
    }
    printf("Case %d: %s after %d transitions\nPlaces with tokens:", ++kase, dead ? "dead" : "still live", num);
    for (int i = 1; i <= NP; ++i)
      if (p[i]) printf(" %d (%d)", i, p[i]);
    puts("\n");
  }
  return 0;
}

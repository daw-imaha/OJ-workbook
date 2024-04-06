#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

struct Card {
  char rank, suit;
  bool operator==(const Card& rhs) const {
    return rank == rhs.rank || suit == rhs.suit;
  }
};

vector<stack<Card>> pile;
int cnt, right[53], left[53];

void link(int L, int R) {
  right[L] = R;
  left[R] = L;
}

int find(int idx, int n) {
  while (idx && n--) idx = left[idx];
  return idx;
}

void accordian(int idx) {
  if (!idx) return;
  int left_pos = 0;
  for (int i = idx; i; i = right[i]) {
    for (int j = 3; j > 0; j -= 2) {
      int k = find(i, j);
      if (k && pile[k].top() == pile[i].top()) {
        pile[k].push(pile[i].top());
        pile[i].pop();
        left_pos = k;
        if (pile[i].empty()) { --cnt; link(left[i], right[i]); }
        break;
      }
    }
    if (left_pos) break;
  }
  accordian(left_pos);
}

int main() {
  char s[3];
  while (scanf("%s", s) && s[0] != '#') {
    pile = vector<stack<Card>>(53, stack<Card>());
    pile[1].push(Card{s[0], s[1]});
    for (int i = 2; i < 53; ++i) {
      scanf("%s", s);
      pile[i].push(Card{s[0], s[1]});
      link(i - 1, i);
    }
    cnt = 52;
    link(0, 1);
    link(52, 0);
    accordian(right[0]);
    printf("%d pile%sremaining:", cnt, cnt > 1 ? "s " : " ");
    for (int i = right[0]; i; i = right[i]) printf(" %d", pile[i].size());
    putchar('\n');
  }
  return 0;
}

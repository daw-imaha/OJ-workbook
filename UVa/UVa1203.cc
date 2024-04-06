#include <cstdio>
#include <queue>

struct Register {
  int Q_num, Period, Time;  // Time: Next execution time
  bool operator<(const Register& rhs) const {
    return Time > rhs.Time || Time == rhs.Time && Q_num > rhs.Q_num;
  }
};

int main() {
  int K;
  char s[10];
  Register r;
  std::priority_queue<Register> pq;
  while (scanf("%s", s) && s[0] != '#') {
    scanf("%d%d", &r.Q_num, &r.Period);
    r.Time = r.Period;
    pq.push(r);
  }
  scanf("%d", &K);
  while (K--) {
    r = pq.top();
    pq.pop();
    printf("%d\n", r.Q_num);
    r.Time += r.Period;
    pq.push(r);
  }
  return 0;
}

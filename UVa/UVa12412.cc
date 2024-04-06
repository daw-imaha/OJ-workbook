#include <cstdio>
#include <cstring>

const int maxl = 15;
const int maxn = 1005;
const double EPS = 1e-5;
const char *course[4] = {"Chinese", "Mathematics", "English", "Programming"};
int n;

struct Student {
  bool removed;
  int cid;
  char sid[maxl];
  char name[maxl];
  int score[5];
} stu[maxn];

void print_menu() {
  printf(
      "Welcome to Student Performance Management System (SPMS).\n\n"
      "1 - Add\n"
      "2 - Remove\n"
      "3 - Query\n"
      "4 - Show ranking\n"
      "5 - Show Statistics\n"
      "0 - Exit\n\n");
}

void add() {
  int cid, score[4], ok;
  char sid[maxn], name[maxl];
  for (;;) {
    puts("Please enter the SID, CID, name and four scores. Enter 0 to finish.");
    ok = 1;
    scanf("%s", sid);
    if (!strcmp(sid, "0")) break;
    scanf("%d%s%d%d%d%d", &cid, name, &score[0], &score[1], &score[2], &score[3]);
    for (int i = 0; i < n; ++i) {
      if (!stu[i].removed && !strcmp(sid, stu[i].sid)) {
        puts("Duplicated SID.");
        ok = 0;
        break;
      }
    }
    if (ok) {
      stu[n].cid = cid;
      strcpy(stu[n].sid, sid);
      strcpy(stu[n].name, name);
      for (int i = 0; i < 4; ++i) {
        stu[n].score[i] = score[i];
        stu[n].score[4] += score[i];
      }
      ++n;
    }
  }
}

void stat() {
  float sum;
  int cid, num, pass, fail, cnt[5] = {0, 0, 0, 0, 0};
  puts("Please enter class ID, 0 for the whole statistics.");
  scanf("%d", &cid);
  for (int i = 0; i < 4; ++i) {
    sum = num = pass = fail = 0;
    for (int j = 0; j < n; ++j) {
      if (!stu[j].removed && (stu[j].cid == cid || !cid)) {
        stu[j].score[i] >= 60 ? ++pass : ++fail;
        sum += stu[j].score[i];
        ++num;
      }
    }
    printf(
        "%s\nAverage Score: %.2f\n"
        "Number of passed students: %d\n"
        "Number of failed students: %d\n\n",
        course[i], num ? sum / num + EPS : 0.00, pass, fail);
  }
  for (int i = 0; i < n; ++i) {
    if (!stu[i].removed && (stu[i].cid == cid || !cid)) {
      pass = 0;
      for (int j = 0; j < 4; ++j)
        if (stu[i].score[j] >= 60) ++pass;
      for (int j = pass ? 1 : 0; j <= pass; ++j) ++cnt[j];
    }
  }
  printf(
      "Overall:\nNumber of students who passed all subjects: %d\n"
      "Number of students who passed 3 or more subjects: %d\n"
      "Number of students who passed 2 or more subjects: %d\n"
      "Number of students who passed 1 or more subjects: %d\n"
      "Number of students who failed all subjects: %d\n\n",
      cnt[4], cnt[3], cnt[2], cnt[1], cnt[0]);
}

int rank(int idx) {
  int m = 1;
  for (int i = 0; i < n; ++i)
    if (!stu[i].removed && stu[i].score[4] > stu[idx].score[4]) ++m;
  return m;
}

void DQ(int isq) {
  int r;
  char s[maxl];
  for (;;) {
    puts("Please enter SID or name. Enter 0 to finish.");
    scanf("%s", s);
    if (!strcmp(s, "0")) break;
    r = 0;
    for (int i = 0; i < n; ++i) {
      if (stu[i].removed || strcmp(stu[i].sid, s) && strcmp(stu[i].name, s))
        continue;
      if (isq)
        printf("%d %s %d %s %d %d %d %d %d %.2f\n", rank(i), stu[i].sid,
               stu[i].cid, stu[i].name, stu[i].score[0], stu[i].score[1],
               stu[i].score[2], stu[i].score[3], stu[i].score[4],
               stu[i].score[4] / 4.0 + EPS);
      else { stu[i].removed = 1; ++r; }
    }
    if (!isq) printf("%d student(s) removed.\n", r);
  }
}

int main() {
  int cmd;
  for (;;) {
    print_menu();
    scanf("%d", &cmd);
    if (!cmd) break;
    else if (cmd == 1) add();
    else if (cmd == 2) DQ(0);
    else if (cmd == 3) DQ(1);
    else if (cmd == 4) puts("Showing the ranklist hurts students' self-esteem. Don't do that.");
    else if (cmd == 5) stat();
  }
  return 0;
}

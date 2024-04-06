#include <cstdio>
#include <cctype>
#include <cstring>
#include <unordered_map>
using namespace std;

struct Array {
  int length;
  unordered_map<int, int> element;
};
unordered_map<char, Array> arr;

int hunt(char *expr) {
  if (isalpha(expr[0])) {
    int idx = hunt(expr + 2);
    return arr[expr[0]].element.count(idx) ? arr[expr[0]].element[idx] : -1;
  } else {
    int n;
    sscanf(expr, "%d", &n);
    return n;
  }
}

int main() {
  char expr[85];
  while (scanf("%s", expr) && expr[0] != '.') {
    arr.clear();
    int bug = 0, row = 0;
    do {
      if (bug) continue;
      if (strchr(expr, '=')) {
        int idx = hunt(expr + 2), val = hunt(strchr(expr, '=') + 1);
        idx >= 0 && idx < arr[expr[0]].length && val >= 0 ? arr[expr[0]].element[idx] = val : bug = 1;
      } else {
        int n;
        char c;
        sscanf(expr, "%c[%d]", &c, &n);
        arr[expr[0]].length = n;
      }
      ++row;
    } while (scanf("%s", expr) && expr[0] != '.');
    printf("%d\n", bug ? row : 0);
  }
  return 0;
}

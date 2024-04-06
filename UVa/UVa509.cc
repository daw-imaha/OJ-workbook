#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

int d, s, b;
char parity;
string disk[7];

int valid_and_recover() {
  for (int i = 0; i < s * b; i++) {
    int n = 0, idx = 0, xorv = parity == 'E' ? 0 : 1;
    for (int j = 0; j < d; j++) {
      if (disk[j][i] == 'x') { n++; idx = j; }
      else xorv ^= disk[j][i] - '0';
    }
    if (n == 1) disk[idx][i] = xorv + '0';
    else if (n > 1 || !n && xorv) return 0;
  }
  return 1;
}

void print_ans() {
  string bin;
  for (int i = 0; i < b; i++) {
    for (int j = 0; j < d; j++) {
      if (j != i % d) bin += disk[j].substr(i * s, s); 
    }
  }
  if (bin.size() % 4) bin += string(4 - bin.size() % 4, '0');
  for (int i = 0; i < bin.size() / 4; i++)
    cout << hex << setiosflags(ios::uppercase) << stoi(bin.substr(i * 4, 4), 0, 2);
  putchar('\n');
}

int main() {
  int kase = 0;
  while (cin >> d && d) {
    cin >> s >> b >> parity;
    for (int i = 0; i < d; i++) cin >> disk[i];
    if (valid_and_recover()) {
      printf("Disk set %d is valid, contents are: ", ++kase);
      print_ans();
    } else printf("Disk set %d is invalid.\n", ++kase);
  }
  return 0;
}

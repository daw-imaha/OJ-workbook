#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Book {
  string author, title;
  Book(string author, string title) : author(author), title(title) {}
  bool operator < (const Book& rhs) const {
    return author < rhs.author || author == rhs.author && title < rhs.title;
  }
};
vector<Book> stock;
map<string, int> status;

int main() {
  string s;
  while (getline(cin, s) && s[0] != 'E') {
    int i = s.find("by");
    status[s.substr(0, i - 1)] = 2;
    stock.push_back(Book(s.substr(i + 3), s.substr(0, i - 1)));
  }
  sort(stock.begin(), stock.end());
  while (getline(cin, s) && s[0] != 'E') {
    if (s[0] == 'S') {
      for (int i = 0; i < stock.size(); ++i) {
        if (!status[stock[i].title]) {
          int pre = -1;
          status[stock[i].title] = 2;
          cout << "Put " << stock[i].title;
          for (int j = 0; j < i; ++j)
            if (status[stock[j].title] == 2) pre = j;
          cout << (pre == -1 ? " first\n" : " after " + stock[pre].title + '\n');
        }
      }
      puts("END");
    } 
    else status[s.substr(s.find(' ') + 1)]--;
  }
  return 0;
}

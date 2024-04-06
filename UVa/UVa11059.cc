#include <cstdio>
#include <algorithm>

int main() {
  int N, M;
  while (~scanf("%d", &N)) {
    int S[20];
    long long P = 0;
    for (int i = 0; i < N; ++i) scanf("%d", &S[i]);
    for (int i = 0; i < N; ++i) {
      for (int j = i; j < N; ++j) {
        long long a = 1;
        for (int k = i; k <= j; ++k) a *= S[k];
        P = std::max(P, a);
      }
    }
    printf("Case #%d: The maximum product is %lld.\n\n", ++M, P);
  }
  return 0;
}

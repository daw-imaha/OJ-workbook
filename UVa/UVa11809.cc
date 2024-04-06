#include <cstdio>
#include <cstring>
#include <cmath>

int B;
double A, a[10][35];
long long b[10][35];
const float EPS = 1e-4;

void init() {
  for (int M = 0; M < 10; ++M) {
    for (int E = 1; E < 31; ++E) {
      double d = log10(1 - pow(2, -1-M)) + (pow(2, E) - 1) * log10(2);
      b[M][E] = d;
      a[M][E] = pow(10, d - b[M][E]);
    }
  }
}

void print_ans() {
  for (int M = 0; M < 10; ++M) {
    for (int E = 1; E < 31; ++E) {
      if (b[M][E] == B && fabs(A - a[M][E]) < EPS) {
        printf("%d %d\n", M, E);
        return;
      }
    }
  }
}

int main() {
  init();
  char F[30];
  while (scanf("%s", F) && strcmp(F, "0e0")) {
    *strchr(F, 'e') = ' ';
    sscanf(F, "%lf%d", &A, &B);  // A * 10^B = C * 2^D;
    print_ans();
  }
  return 0;
}

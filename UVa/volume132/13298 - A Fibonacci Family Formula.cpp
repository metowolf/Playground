#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
const long long mod = 1000000009;

struct Matrix {
  int n, m;
  long long a[maxn + 2][maxn + 2];

  Matrix(int n, int m) {
    this->n = n;
    this->m = m;
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= m; j++)
        a[i][j] = 0;
  }

  Matrix operator*(const Matrix& b) const {
    Matrix c(n, b.m);
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < m; k++) {
        if (a[i][k]) {
          for (int j = 0; j < b.m; j++) {
            c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % mod;
          }
        }
      }
    }
    return c;
  }

  Matrix operator^(long long k) const {
    Matrix c(n, m);
    for (int i = 0; i < n; i++) c.a[i][i] = 1;
    Matrix b = *this;
    while (k) {
      if (k & 1) c = c * b;
      b = b * b;
      k >>= 1;
    }
    return c;
  }
};

int main() {
  long long k, n;
  while (~scanf("%lld%lld", &k, &n)) {

    if (k == 0 && n == 0) {
      break;
    }

    if (n == 0) {
      printf("1\n");
      continue;
    }

    Matrix a(k, k);
    for (int i = 0; i < k; i++) {
      a.a[0][i] = 1;
    }
    for (int i = 1; i < k; i++) {
      a.a[i][i - 1] = 1;
    }
    Matrix b = a ^ n;

    printf("%lld\n", b.a[0][0]);
  }
  return 0;
}
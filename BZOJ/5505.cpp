#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = a; i <= b; ++i)
using namespace std;

const int maxn = 6 + 2;
const long long mod = 1e9 + 7;

struct Matrix {

  int n;
  long long v[maxn][maxn];

  Matrix() {}
  Matrix(int _n) {
    n = _n;
    memset(v, 0, sizeof(v));
  }

  friend Matrix operator + (Matrix a, Matrix b) {
    int n = a.n;
    Matrix c(n);
    REP(i, 1, n) REP(j, 1, n) c.v[i][j] = (a.v[i][j] + b.v[i][j]) % mod;
    return c;
  }

  friend Matrix operator * (Matrix a, Matrix b) {
    int n = a.n;
    Matrix c(n);
    REP(i, 1, n)
    REP(j, 1, n) if (a.v[i][j]) REP(k, 1, n)
        c.v[i][k] = (c.v[i][k] + a.v[i][j] * b.v[j][k] % mod) % mod;
    return c;
  }

  friend Matrix operator ^ (Matrix a, int k) {
    int n = a.n;
    Matrix c(n);
    REP(i, 1, n) c.v[i][i] = 1;
    while (k) {
      if (k & 1)
        c = c * a;
      a = a * a;
      k >>= 1;
    }
    return c;
  }
};

/*
f[i][0]=f[i-1][0]+f[i-2][0]
f[i][1]=2*f[i-1][0]+f[i-1][1]
f]i][2]=f[i-1][2]+f[i-2][2]+f[i-2][1]
*/

int solve(int n) {
  Matrix t(6);
  t.v[1][1] = 1;
  t.v[1][4] = 1;
  t.v[2][1] = 2;
  t.v[2][2] = 1;
  t.v[3][3] = 1;
  t.v[3][5] = 1;
  t.v[3][6] = 1;
  t.v[4][1] = 1;
  t.v[5][2] = 1;
  t.v[6][3] = 1;
  t = t ^ n;
  Matrix ans(6);
  ans.v[1][1] = 1;
  ans = t * ans;
  return ans.v[3][1];
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", solve(n));
  }
}

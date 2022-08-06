#include <bits/stdc++.h>
using namespace std;

int check(int y, int m, int d) {
  if (m == 2 && d == 29) {
    return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
  }
  return 1;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int kase = 1; kase <= T; kase++) {
    int d, m, y, yy;
    scanf("%d%d%d%d", &d, &m, &y, &yy);
    int ans = 0;
    for (int i = y + 1; i <= yy; i++) {
      ans += check(i, m, d);
    }
    printf("Case %d: %d\n", kase, ans);
  }
}
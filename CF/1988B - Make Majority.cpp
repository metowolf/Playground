#include<bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  char s[200000 + 5];
  scanf("%d %s", &n, s);

  int cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      cnt1++;
    }
  }

  // 合并相邻的 0 为一个 0
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      cnt0++;
      while (i < n && s[i] == '0') {
        i++;
      }
    }
  }

  printf("%s\n", cnt1 > cnt0 ? "Yes" : "No");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
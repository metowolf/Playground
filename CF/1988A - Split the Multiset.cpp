#include<bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  printf("%d\n", (n-1)/(k-1) + ((n-1)%(k-1)>0?1:0));
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
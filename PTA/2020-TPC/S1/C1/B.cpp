#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 100000;
char s1[maxn + 2], s2[maxn + 2];

void solve () {
    int n;
    scanf("%d", &n);
    scanf("%s", s1);
    scanf("%s", s2);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            if (i && s1[i] == s1[i - 1]) {
                printf("-1\n");
                return;
            }
            ans++;
            char ch = s1[i];
            for (int j = i; j < n; j++) {
                if (s1[j] == ch) {
                    s1[j] = s2[i];
                } else {
                    break;
                }
            }
        }
    }
    printf("%d\n", ans);
    return;
}

int main () {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
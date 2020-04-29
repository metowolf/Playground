#include <iostream>
#include <cstdio>

using namespace std;

int solve (int n) {
    if (n == 1) return 1;
    return n / 2;
}

int main () {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", solve(n));
    }
    return 0;
}
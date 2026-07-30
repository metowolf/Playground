#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

bool gao(LL n, LL m, LL d, vector<LL> a, vector<LL> b) {
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j < m && b[j] < a[i] - d) {
            ++j;
        }
        if (j == m || b[j] > a[i] + d) {
            return false;
        }
        ++j;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >>m;

        vector<LL> a(n), b(m);

        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < m; ++i) cin >> b[i];

        LL l = -1LL;
        LL r = 1000000000LL;

        while (r - l > 1) {
            LL mid = (l + r) / 2;

            if (gao(n, m, mid, a, b)) {
                r = mid;
            } else {
                l = mid;
            }
        }

        cout << r << endl;

    }
    return 0;
}
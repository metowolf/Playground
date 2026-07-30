#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >>m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        sort(a.begin(), a.end());

        bool ok = true;
        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] > a[i + 1][j]) {
                    ok = false;
                }
            }
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}
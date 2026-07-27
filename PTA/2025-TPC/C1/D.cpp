#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<int> d(n + 1);
        vector<vector<int>> g(n + 1);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;

            d[u]++;
            d[v]++;

            if (u > v) swap(u, v);
            g[u].push_back(v);
        }

        vector<int> ds;
        for (int i = 1; i <= n; i++) {
            if (d[i] > 0) {
                ds.push_back(d[i]);
            }
        }

        sort(ds.begin(), ds.end());
        ds.erase(unique(ds.begin(), ds.end()), ds.end());

        const ll inf = -(1LL << 60);
        ll ans = LLONG_MIN;
        vector<ll> f(n + 1);

        for (int x : ds) {
            fill(f.begin(), f.end(), inf);

            for (int u = 1; u <= n; u++) {
                if (d[u] == x) {
                    f[u] = max(f[u], a[u]);
                }

                if (f[u] == inf) continue;

                for (int v : g[u]) {
                    ll z = f[u] + a[v];
                    ans = max(ans, z * (x + d[v] - 2LL));
                    f[v] = max(f[v], z);
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
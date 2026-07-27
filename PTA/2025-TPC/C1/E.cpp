#include <bits/stdc++.h>
using namespace std;

struct Node {
    int mn, cnt, tag;
};

struct Seg {
    int n;
    vector<Node> tr;

    Seg(int n) : n(n), tr(n * 4 + 4) {
        build(1, 1, n);
    }

    void build(int p, int l, int r) {
        tr[p].mn = tr[p].tag = 0;
        tr[p].cnt = r - l + 1;
        if (l == r) return;
        int m = (l + r) >> 1;
        build(p << 1, l, m);
        build(p << 1 | 1, m + 1, r);
    }

    void apply(int p, int v) {
        tr[p].mn += v;
        tr[p].tag += v;
    }

    void push(int p) {
        if (tr[p].tag) {
            apply(p << 1, tr[p].tag);
            apply(p << 1 | 1, tr[p].tag);
            tr[p].tag = 0;
        }
    }

    void pull(int p) {
        tr[p].mn = min(tr[p << 1].mn, tr[p << 1 | 1].mn);
        tr[p].cnt = 0;
        if (tr[p << 1].mn == tr[p].mn)
            tr[p].cnt += tr[p << 1].cnt;
        if (tr[p << 1 | 1].mn == tr[p].mn)
            tr[p].cnt += tr[p << 1 | 1].cnt;
    }

    void add(int p, int l, int r, int x, int y, int v) {
        if (x > y || y < l || r < x) return;
        if (x <= l && r <= y) {
            apply(p, v);
            return;
        }
        push(p);
        int m = (l + r) >> 1;
        add(p << 1, l, m, x, y, v);
        add(p << 1 | 1, m + 1, r, x, y, v);
        pull(p);
    }

    void add(int l, int r, int v) {
        if (l <= r) add(1, 1, n, l, r, v);
    }

    pair<int, int> ask(int p, int l, int r, int x, int y) {
        if (x <= l && r <= y)
            return {tr[p].mn, tr[p].cnt};

        push(p);
        int m = (l + r) >> 1;
        pair<int, int> res = {INT_MAX, 0};

        if (x <= m) {
            auto q = ask(p << 1, l, m, x, y);
            if (q.first < res.first)
                res = q;
            else if (q.first == res.first)
                res.second += q.second;
        }

        if (y > m) {
            auto q = ask(p << 1 | 1, m + 1, r, x, y);
            if (q.first < res.first)
                res = q;
            else if (q.first == res.first)
                res.second += q.second;
        }

        return res;
    }

    pair<int, int> ask(int r) {
        return ask(1, 1, n, 1, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> a(n + 1);
        vector<vector<int>> p(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        Seg st(n);
        long long ans = 0;

        for (int i = 1; i <= n; i++) {
            int x = a[i];
            p[x].push_back(i);

            int k = p[x].size();

            if (l > 1) {
                int z = (k == 1 ? 0 : p[x][k - 2]);
                st.add(z + 1, i, 1);

                if (k >= l) {
                    int L = (k == l ? 1 : p[x][k - l - 1] + 1);
                    int R = p[x][k - l];
                    st.add(L, R, -1);
                }
            }

            if (k >= r + 1) {
                int L = (k == r + 1 ? 1 : p[x][k - r - 2] + 1);
                int R = p[x][k - r - 1];
                st.add(L, R, 1);
            }

            auto q = st.ask(i);
            if (q.first == 0)
                ans += q.second;
        }

        cout << ans << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

struct edge {
    int from, to, dis, nxt;
};

vector<edge> E;
vector<int> head, dis, vis;
int S, tot;

void addEdge(int u, int v, int w) {
    // cout << u << "->" << v << " : " << w << endl;
    edge e;
    e.from = u;
    e.to = v;
    e.dis = w;
    e.nxt = head[u];
    E.push_back(e);
    head[u] = tot++;
}

void SPFA() {
    queue<int> Q;
    int n = head.size();

    dis.assign(n, INF);
    vis.assign(n, 0);

    dis[S] = 0;
    vis[S] = 1;
    Q.push(S);

    while (!Q.empty()) {
        int t = Q.front();
        Q.pop();
        vis[t] = 0;

        for (int i = head[t]; ~i; i = E[i].nxt) {
            edge &e = E[i];

            if (dis[e.from] + e.dis < dis[e.to]) {
                dis[e.to] = dis[e.from] + e.dis;

                if (!vis[e.to]) {
                    vis[e.to] = 1;
                    Q.push(e.to);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >>m;

        vector<vector<int> > g(n + 1);
        vector<int> rev(2 * m);

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;

            int x = 2 * i;
            int y = x + 1;

            rev[x] = y;
            rev[y] = x;

            g[u].push_back(x);
            g[v].push_back(y);
        }

        int z = 2 * m;
        S = 4 * m;
        int N = S + 1;

        head.assign(N, -1);
        E.clear();
        E.reserve(8 * m + 5);
        tot = 0;

        for (int u = 1; u <= n; ++u) {
            // cout << "u=" << u+1 << endl;
            int d = g[u].size();

            if (d == 0) {
                continue;
            }

            int f = g[u][0];

            for (int i = 0; i < d; ++i) {
                int x = g[u][i];
                // cout << "edge=" << x/2+1 << endl;

                addEdge(x, z + f, 1);

                if (i + 1 < d) {
                    addEdge(x, z + g[u][i + 1], 0);
                }

                addEdge(z + x, rev[x], 0);

                if (i + 1 < d) {
                    addEdge(z + x, z + g[u][i + 1], 0);
                }
            }
        }

        if (!g[1].empty()) {
            addEdge(S, z + g[1][0], 1);
        }

        SPFA();

        for (int u = 2; u <= n; ++u) {
            int ans = INF;

            for (int i = 0; i < (int)g[u].size(); ++i) {
                ans = min(ans, dis[g[u][i]]);
            }

            if (u > 2) {
                cout << ' ';
            }

            if (ans == INF) {
                cout << -1;
            } else {
                cout << ans;
            }
        }

        cout << '\n';
    }

    return 0;
}
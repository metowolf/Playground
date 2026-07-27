#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<pair<long long, long long>> intervals(n);
        vector<long long> endpoints;
        endpoints.reserve(2 * n);

        for (int i = 0; i < n; ++i) {
            long long l, r;
            cin >> l >> r;

            intervals[i] = {l, r};
            endpoints.push_back(l);
            endpoints.push_back(r);
        }

        sort(endpoints.begin(), endpoints.end());

        long long x = endpoints[n - 1];

        long long answer = 0;

        for (const auto& interval : intervals) {
            long long l = interval.first;
            long long r = interval.second;

            if (x < l) {
                answer += l - x;
            } else if (x > r) {
                answer += x - r;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
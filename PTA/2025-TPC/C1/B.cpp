#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        vector<int> zero_runs;
        int first_one = static_cast<int>(s.find('1'));

        for (int i = first_one + 1; i < n;) {
            if (s[i] == '1') {
                ++i;
                continue;
            }

            int j = i;
            while (j < n && s[j] == '0') {
                ++j;
            }
            zero_runs.push_back(j - i);
            i = j;
        }

        sort(zero_runs.begin(), zero_runs.end());

        int remaining_breaks = static_cast<int>(zero_runs.size());
        for (int length : zero_runs) {
            if (length > k) {
                break;
            }
            k -= length;
            --remaining_breaks;
        }

        cout << remaining_breaks << '\n';
    }

    return 0;
}

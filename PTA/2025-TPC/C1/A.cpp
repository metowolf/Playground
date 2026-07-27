#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const string types = "OBAFGKM";

    int T;
    cin >> T;

    while (T--) {
        string c;
        int k;
        cin >> c >> k;

        int letterIndex = types.find(c[0]);
        int id = letterIndex * 10 + (c[1] - '0');

        int answerId = id - k;

        if (answerId < 0) {
            cout << "Invalid\n";
            continue;
        }

        cout << types[answerId / 10]
             << answerId % 10 << '\n';
    }

    return 0;
}
#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_map<int, int> Hash;
queue<int> Queue;

int change (int x, int kase) {
    int num[9];
    for (int i = 8; i >= 0; i--) {
        num[i] = x % 10;
        x /= 10;
    }
    if (kase == 1) {
        int t = num[6];
        num[6] = num[3];
        num[3] = num[0];
        num[0] = t;
    } else if (kase == 2) {
        int t = num[7];
        num[7] = num[4];
        num[4] = num[1];
        num[1] = t;
    } else if (kase == 3) {
        int t = num[8];
        num[8] = num[5];
        num[5] = num[2];
        num[2] = t;
    } else if (kase == 4) {
        int t = num[2];
        num[2] = num[1];
        num[1] = num[0];
        num[0] = t;
    } else if (kase == 5) {
        int t = num[5];
        num[5] = num[4];
        num[4] = num[3];
        num[3] = t;
    } else if (kase == 6) {
        int t = num[8];
        num[8] = num[7];
        num[7] = num[6];
        num[6] = t;
    }
    int result = 0;
    for (int i = 0; i < 9; i++) {
        result = result * 10 + num[i];
    }
    return result;
}

void table () {
    int t = 123456789;
    Queue.push(t);
    Hash[t] = 1;
    while (!Queue.empty()) {
        int temp = Queue.front();
        Queue.pop();
        int temp_count = Hash[temp];
        // printf("%d %d\n", temp, temp_count);
        for (int i = 1; i <= 6; i++) {
            int tt = change(temp, i);
            if (Hash[tt]) continue;
            else {
                Hash[tt] = temp_count + 1;
                Queue.push(tt);
            }
        }
    }
}

int main () {
    table();
    int T;
    scanf("%d", &T);
    while (T--) {
        int a[9], b[9], dist[10];
        for (int i = 0; i < 9; i++) {
            char ch;
            scanf(" %c", &ch);
            a[i] = ch - '0';
            dist[a[i]] = i + 1;
            // printf("%d", a[i]);
        }
        // printf("\n");
        for (int i = 0; i < 9; i++) {
            char ch;
            scanf(" %c", &ch);
            b[i] = ch - '0';
            b[i] = dist[b[i]];
        }
        int t = 0;
        for (int i = 0; i < 9; i++) {
            t = t * 10 + b[i];
        }
        // printf("%d\n", t);
        if (Hash[t]) {
            printf("%d\n", Hash[t] - 1);
        } else {
            printf("impossible\n");
        }
    }
    return 0;
}
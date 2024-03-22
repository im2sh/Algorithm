#include <iostream>
#include <vector>
#include <map>

using namespace std;
int N, ret;
int dest[51];
int seq[51];
map<vector<int>, int> deck;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> dest[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> seq[i];
    }
}

void solve() {
    while (true) {
        bool flag = true;
        for (int i = 0; i < N; i++) {
            if (i % 3 != dest[i]) {
                flag = false;
                break;
            }
        }

        if (flag)
            break;
        ret++;
        int temp[51] = {0,};
        memcpy(temp, dest, sizeof(dest));
        for (int i = 0; i < N; i++) {
            temp[seq[i]] = dest[i];
        }
        vector<int> tt;
        memcpy(dest, temp, sizeof(dest));
        for (int i = 0; i < N; i++) {
            tt.push_back(dest[i]);
        }
        deck[tt]++;
        if (deck[tt] > 1) {
            cout << "-1";
            return;
        }
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
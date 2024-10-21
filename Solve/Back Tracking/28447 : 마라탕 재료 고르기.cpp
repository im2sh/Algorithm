#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, ret = -987654321;
vector<int> choice;
int BOARD[11][11];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> BOARD[y][x];
        }
    }
}

void go(int depth, int idx) {
    if (depth == K) {
        int sum = 0;
        for (int i = 0; i < choice.size(); i++) {
            for (int j = i + 1; j < choice.size(); j++) {
                sum += BOARD[choice[i]][choice[j]];
            }
        }
        ret = max(ret, sum);
        return;
    }

    for (int i = idx; i < N; i++) {
        choice.push_back(i);
        go(depth + 1, i + 1);
        choice.pop_back();
    }
}

void solve() {
    go(0, 0);
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
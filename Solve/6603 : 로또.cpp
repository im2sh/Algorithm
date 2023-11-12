#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> lotto;
int ret[6];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void dfs(int depth, int start) {
    if (depth == 6) {
        for (int i = 0; i < 6; i++) {
            cout << ret[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = start; i < N; i++) {
        ret[depth] = lotto[i];
        dfs(depth + 1, i + 1);
    }
}

void solve() {
    int temp;
    while (true) {
        lotto.clear();
        cin >> N;
        if (N == 0) {
            break;
        }
        for (int i = 0; i < N; i++) {
            cin >> temp;
            lotto.push_back(temp);
        }
        dfs(0, 0);
        cout << '\n';
    }
}

int main(void) {
    FastIO();
    solve();
    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K, ret = -1;
vector<string> lamp;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    string temp;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        lamp.push_back(temp);
    }
    cin >> K;
}

void solve() {
    string line;
    for (int i = 0; i < N; i++) {
        line = lamp[i];
        int cnt = 0;
        int zero_cnt = 0;
        for (int j = 0; j < M; j++) {
            if (line[j] == '0')
                zero_cnt++;
        }

        if (zero_cnt <= K && K % 2 == zero_cnt % 2) {
            for (int j = i; j < N; j++) {
                if (line == lamp[j]) {
                    cnt++;
                }
            }
        }
        ret = max(ret, cnt);
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
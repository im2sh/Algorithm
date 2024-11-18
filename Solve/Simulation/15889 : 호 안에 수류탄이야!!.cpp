#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> pos;
vector<int> dist;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        pos.push_back(temp);
    }

    dist.push_back(0);
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        dist.push_back(temp);
    }
}

void solve() {
    if (N == 1) {
        cout << "권병장님, 중대장님이 찾으십니다";
        return;
    }

    int temp = 0;
    for (int i = 1; i < N; i++) {
        if (temp < pos[i - 1] + dist[i])
            temp = pos[i - 1] + dist[i];
        if (temp < pos[i]) {
            cout << "엄마 나 전역 늦어질 것 같아";
            return;
        }
    }
    cout << "권병장님, 중대장님이 찾으십니다";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
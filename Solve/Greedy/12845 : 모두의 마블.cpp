#include <iostream>
#include <vector>

using namespace std;

int N, maxIdx, ret;
vector<int> card;

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
        card.push_back(temp);
        if (card[maxIdx] < card[i]) {
            maxIdx = i;
        }
    }
}

void solve() {
    for (int i = maxIdx - 1; i >= 0; i--) {
        ret += card[maxIdx] + card[i];
    }
    for (int i = maxIdx + 1; i < N; i++) {
        ret += card[maxIdx] + card[i];
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
#include <iostream>
#include <deque>

using namespace std;

int N, K, ret;
deque<pair<bool, int>> BELT;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int x;
    cin >> N >> K;
    for (int i = 0; i < N * 2; i++) {
        cin >> x;
        BELT.push_back({false, x});
    }
}

void display() {
    for (int i = 0; i < 2 * N; i++) {
        cout << BELT[i].second << " ";
    }
    cout << "\n";
}

void solve() {
    int zero = 0;

    while (zero < K) {
//        display();
//        cout << "\n";
        ret++;
        pair<bool, int> temp = BELT.back();
        BELT.pop_back();
        BELT.push_front(temp);

        if (BELT[N - 1].first)
            BELT[N - 1].first = false;

        for (int i = N - 2; i >= 0; i--) {
            int next = i + 1;
            if (!(BELT[i].first) || BELT[next].first || BELT[next].second <= 0)
                continue;
            BELT[next].first = true;
            BELT[next].second--;
            BELT[i].first = false;
        }

        if (BELT[N - 1].first)
            BELT[N - 1].first = false;

        if (!BELT[0].first && BELT[0].second > 0) {
            BELT[0].first = true;
            BELT[0].second--;
        }

        zero = 0;
        for (int i = 0; i < N * 2; i++) {
            if (BELT[i].second == 0)
                zero++;
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    cout << ret;
    return 0;
}
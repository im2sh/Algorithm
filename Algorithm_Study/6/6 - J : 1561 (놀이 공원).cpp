#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

ll N, M, ret;
vector<int> play;
ll low = 1;
ll high = 60000000001;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        play.push_back(temp);
    }
}

bool check(ll mid) {
    ll temp = M;
    for (int i = 0; i < M; i++) {
        temp += mid / play[i];
    }
    return temp >= N;
}

void solve() {
    if (N <= M) {
        cout << N;
        return;
    }

    while (low <= high) {
        ll mid = (low + high) / 2;
        if (check(mid)) {
            high = mid - 1;
            ret = mid;
        } else {
            low = mid + 1;
        }
    }

    ll temp = M;

    for (int i = 0; i < M; i++) {
        temp += (ret - 1) / play[i];
    }

    for (int i = 0; i < M; i++) {
        if (ret % play[i] == 0)
            temp++;
        if (temp == N) {
            cout << i + 1;
            break;
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
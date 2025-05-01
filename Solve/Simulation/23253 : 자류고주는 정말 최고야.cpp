#include <iostream>

using namespace std;

int N, M;
bool flag = true;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
}

void solve() {
    while (M--) {
        int K;
        cin >> K;
        int past = N + 1;
        while (K--) {
            int x;
            cin >> x;
            if (x > past)
                flag = false;
            past = x;
        }
    }

    if (flag)
        cout << "Yes";
    else
        cout << "No";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
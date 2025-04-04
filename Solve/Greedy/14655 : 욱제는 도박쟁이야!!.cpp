#include <iostream>

using namespace std;

int N, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    int temp;
    
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp < 0)
            ret += (-1 * temp);
        else
            ret += temp;
    }

    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp < 0)
            ret += (-1 * temp);
        else
            ret += temp;
    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
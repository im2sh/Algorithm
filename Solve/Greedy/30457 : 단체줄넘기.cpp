#include <iostream>
#include <algorithm>

using namespace std;

int N, ret;
int student[1004];

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
        student[temp]++;
    }
}

void solve() {
    for (int i = 1; i <= 1000; i++) {
        ret += min(2, student[i]);
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
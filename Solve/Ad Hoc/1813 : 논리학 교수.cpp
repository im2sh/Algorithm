#include <iostream>

using namespace std;

int N;
int visited[100004];

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
        visited[temp]++;
    }
}

void solve() {
    for (int i = N; i >= 0; i--) {
        if (visited[i] == i) {
            cout << i;
            return;
        }
    }
    cout << "-1";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
#include <iostream>
#include <map>

using namespace std;

int N, ret;
map<int, int> M;

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
        M[temp]++;
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if (!M.count(temp) || !M[temp])
            ret++;
        else
            M[temp]--;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
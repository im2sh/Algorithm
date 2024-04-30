#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int N1, N2, T;
string R, L, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N1 >> N2;
    cin >> R;
    cin >> L;
    cin >> T;
}

void solve() {
    reverse(R.begin(), R.end());
    ret = R + L;
    int t = 0;
    while (t < T) {
        for (int i = 0; i < N1 + N2 - 1; i++) {
            if (R.find(ret[i]) != string::npos && L.find(ret[i + 1]) != string::npos) {
                swap(ret[i], ret[i + 1]);
                i++;
            }
        }
        t++;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}



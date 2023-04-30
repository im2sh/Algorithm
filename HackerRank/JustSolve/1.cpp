#include <iostream>
#include <string>

using namespace std;

string target;
int ret = 0;
int flip = 0;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> target;
}

void solve() {
    for (int i = 0; i < target.length(); i++) {
        int n = target[i] - '0';
        int bit = (flip + n) % 2;
        if (bit == 1) {
            flip = 1 - flip;
            ret++;
        }
    }
    cout << ret << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
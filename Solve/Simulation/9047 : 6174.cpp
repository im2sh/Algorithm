#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int TC, N, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    ret = 0;
    cin >> N;
}

void solve() {
    while (TC--) {
        Input();
        while (N != 6174) {
            string temp = to_string(N);
            while (temp.length() != 4)
                temp = "0" + temp;
            sort(temp.begin(), temp.end());

            string newTemp = temp;
            reverse(newTemp.begin(), newTemp.end());
            N = abs(stoi(newTemp) - stoi(temp));
            ret++;
        }
        cout << ret << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
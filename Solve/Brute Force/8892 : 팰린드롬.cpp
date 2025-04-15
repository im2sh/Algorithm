#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int TC, N;
vector<string> arr;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    arr.clear();
    cin >> N;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        arr.push_back(temp);
    }
}

bool check(string str) {
    int len = str.length();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] == str[len - i - 1])
            continue;
        else
            return false;
    }
    return true;
}

void go() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                continue;

            if (check(arr[i] + arr[j])) {
                cout << arr[i] + arr[j] << '\n';
                return;
            }
        }
    }

    cout << 0 << '\n';
}

void solve() {
    while (TC--) {
        Input();
        go();
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
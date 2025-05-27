#include <iostream>
#include <set>
#include <string>

using namespace std;

int N, M, idx;
string arr[101];
set<string> dict;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];

        if (arr[i] == "?")
            idx = i;
        else
            dict.insert(arr[i]);
    }
    cin >> M;
}

void solve() {
    for (int i = 0; i < M; i++) {
        string temp;
        cin >> temp;
        if (idx > 0) {
            if (temp.front() != arr[idx - 1].back())
                continue;
        }
        if (idx + 1 < N) {
            if (temp.back() != arr[idx + 1].front())
                continue;
        }
        if (dict.count(temp))
            continue;
        cout << temp;
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
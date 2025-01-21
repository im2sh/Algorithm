#include <iostream>
#include <string>

using namespace std;

int N, ret;
string target;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> target;
    cin >> N;
}

void solve() {
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        temp += temp;
        if (temp.find(target) != string::npos)
            ret++;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
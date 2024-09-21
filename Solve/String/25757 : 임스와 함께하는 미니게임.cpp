#include <iostream>
#include <set>

using namespace std;

int N;
char game;
set<string> s;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> game;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        s.insert(temp);
    }
}

void solve() {
    if (game == 'Y') {
        cout << s.size();
    } else if (game == 'F') {
        cout << s.size() / 2;
    } else {
        cout << s.size() / 3;
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
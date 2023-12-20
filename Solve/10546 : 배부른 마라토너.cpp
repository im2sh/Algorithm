#include <iostream>
#include <map>

using namespace std;
int N;
map<string, int> maratoner;
string ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    string temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        maratoner[temp]++;
    }

    for (int i = 0; i < N - 1; i++) {
        cin >> temp;
        maratoner[temp]--;
    }
}

void solve() {
    for (auto it: maratoner)
        if (it.second != 0)
            ret = it.first;
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
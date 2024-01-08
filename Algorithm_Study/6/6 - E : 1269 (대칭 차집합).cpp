#include <iostream>
#include <map>

using namespace std;

int N, M;
map<int, bool> MP;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
}

void solve() {
    int temp;
    for (int i = 0; i < N + M; i++) {
        cin >> temp;
        if (MP[temp])
            MP.erase(temp);
        else
            MP[temp] = true;
    }
    cout << MP.size();
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
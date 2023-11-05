#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> elec;

void FastIO(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        elec.push_back(temp);
    }
}

void solve() {
    sort(elec.begin(), elec.end());
    cout << elec[(N - 1) / 2];
}


int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
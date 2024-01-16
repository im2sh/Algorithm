#include <iostream>
#include <vector>

using namespace std;
int N;
vector<int> v;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    int temp;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        v.insert(v.begin() + temp, i);
    }


    for (int i = N - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

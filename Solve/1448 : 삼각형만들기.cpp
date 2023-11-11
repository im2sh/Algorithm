#include <iostream>
#include <vector>
#include <algorithm>

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
    int temp = 0;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), greater<>());
}

void solve() {
    int i = 0;
    while (1) {
        if (v[i] < v[i + 1] + v[i + 2]) {
            cout << v[i] + v[i + 1] + v[i + 2] << '\n';
            break;
        }
        i++;
        if (i + 2 >= N) {
            cout << -1 << '\n';
            break;
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
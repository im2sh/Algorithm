#include <iostream>
#include <vector>

using namespace std;
int N, S, E, Q;
int seat[1000004];
vector<int> v;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S >> E;
        seat[S]++;
        seat[E + 1]--;
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> temp;
        v.push_back(temp);
    }
}

void solve() {
    for (int i = 1; i < 1000004; i++) {
        seat[i] = seat[i] + seat[i - 1];
    }

    for (int i = 0; i < Q; i++) {
        cout << seat[v[i]] << '\n';
    }

}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
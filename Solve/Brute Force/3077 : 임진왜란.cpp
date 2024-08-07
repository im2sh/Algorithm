#include <iostream>
#include <map>
#include <vector>

using namespace std;
int N, ret;
map<string, int> M;
vector<string> x;


void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    string s;
    cin >> N;
    int temp = N;
    while (temp--) {
        cin >> s;
        M[s] = N - temp;
    }

    temp = N;
    while (temp--) {
        cin >> s;
        x.push_back(s);
    }
}

void solve() {
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (M[x[i]] < M[x[j]])
                ret++;
        }
    }

    cout << ret << '/' << N * (N - 1) / 2;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
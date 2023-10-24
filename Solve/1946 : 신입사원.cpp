#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
vector<pair<int, int>> grade;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> T;
}

void solve() {
    while (T--) {
        int temp = 0;
        int ret = 1;
        grade.clear();

        cin >> N;

        for (int i = 0; i < N; i++) {
            int a, b;
            cin >> a >> b;
            grade.push_back({a, b});
        }
        sort(grade.begin(), grade.end());

        for (int i = 1; i < N; i++) {
            if (grade[temp].second > grade[i].second) {
                ret++;
                temp = i;
            }
        }
        cout << ret << '\n';
    }
}

int main() {
    FastIO();
    Init();
    solve();
    return 0;
}
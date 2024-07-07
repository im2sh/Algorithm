#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int TC, J, N, ret;
vector<int> box;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void solve() {
    while (TC--) {
        cin >> J >> N;
        box.clear();
        ret = 0;
        for (int i = 0; i < N; i++) {
            int r, c;
            cin >> r >> c;
            box.push_back(r * c);
        }

        sort(box.begin(), box.end());
        for (int i = N - 1; i > 0; i--) {
            J -= box[i];
            ret++;

            if (J <= 0)
                break;
        }

        cout << ret << "\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
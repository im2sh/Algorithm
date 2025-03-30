#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    for (int i = 1; i <= N; i++) {
        vector<int> temp;
        temp.push_back(N);
        temp.push_back(i);

        for (int j = 1;; j++) {
            if (temp[j - 1] - temp[j] < 0)
                break;
            temp.push_back(temp[j - 1] - temp[j]);
        }
        if (temp.size() > ret.size())
            ret = temp;
    }
    cout << ret.size() << '\n';
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << ' ';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
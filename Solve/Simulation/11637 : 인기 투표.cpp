#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int TC, N, maxNum, idx, cnt, sum;
vector<int> v;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    v.clear();
    idx = 0;
    maxNum = 0;
    cnt = 0;
    sum = 0;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);

        if (temp > maxNum) {
            maxNum = temp;
            idx = i;
        }
    }
    sort(v.begin(), v.end(), greater<int>());
}

void solve() {
    while (TC--) {
        Input();
        for (int i = 0; i < v.size(); i++) {
            if (v[0] == v[1])
                cnt++;
            sum += v[i];
        }

        if (cnt == 0) {
            if (sum - v[0] < v[0]) {
                cout << "majority winner " << idx << "\n";
            } else if (sum - v[0] >= v[0]) {
                cout << "minority winner " << idx << "\n";
            }
        } else if (cnt >= 1) {
            cout << "no winner\n";
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
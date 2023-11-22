#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L;
vector<int> v;
int ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> L;
    for (int i = 0; i < L; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    cin >> N;

    sort(v.begin(), v.end());
}

void solve() {
    bool flag = false;
    for (int i = 0; i < L; i++) {
        if (v[i] == N) {
            flag = true;
            break;
        }
    }

    if (flag) {
        cout << 0 << "\n";
    } else {
        int start = 0;
        int end = 0;

        for (int i = 0; i < L; i++) {
            if (v[i] > N) {
                start = v[i - 1];
                end = v[i];
                break;
            }
        }

        for (int i = start + 1; i < end; i++) {
            for (int j = i + 1; j < end; j++) {
                if (i <= N && N <= j) {
                    ret++;
                }
            }
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
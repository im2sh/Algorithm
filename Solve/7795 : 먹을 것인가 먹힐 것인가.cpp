#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M, temp;
int low, high, mid;
int ret;

vector<int> a;
vector<int> b;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> T;
}

void QInit() {
    cin >> N >> M;
    for (int j = 0; j < N; j++) {
        cin >> temp;
        a.push_back(temp);
    }

    for (int j = 0; j < M; j++) {
        cin >> temp;
        b.push_back(temp);
    }
}

void solve() {
    for (int i = 0; i < T; i++) {
        a.clear();
        b.clear();

        QInit();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        ret = 0;

        for (int x: a) {
            low = 0;
            high = M - 1;

            while (low <= high) {
                mid = (low + high) / 2;
                if (b[mid] < x) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            ret += low;
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



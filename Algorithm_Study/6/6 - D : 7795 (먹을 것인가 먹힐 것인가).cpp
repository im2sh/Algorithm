#include <iostream>
#include <vector>

using namespace std;

vector<int> A, B;
int T, N, M;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> T;
}

void VInit() {
    int temp;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        A.push_back(temp);
    }
    for (int i = 0; i < M; i++) {
        cin >> temp;
        B.push_back(temp);
    }
}

void solve() {
    for (int i = 0; i < T; i++) {
        int ret = 0;
        A.clear();
        B.clear();
        VInit();
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        for (auto &it: A) {
            int low = 0;
            int high = M - 1;

            while (low <= high) {
                int mid = (low + high) / 2;
                if (it > B[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            ret += low;
        }
        cout << ret << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
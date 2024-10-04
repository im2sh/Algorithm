#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ret, retA, retB;
vector<int> A;
vector<int> B;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        B.push_back(temp);
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        if (A[i] == 1 && B[i] == 2) {
            retA = 0;
            retB++;
        } else if (A[i] == 2 && B[i] == 3) {
            retA = 0;
            retB++;
        } else if (A[i] == 3 && B[i] == 1) {
            retA = 0;
            retB++;
        } else if (B[i] == 1 && A[i] == 2) {
            retA++;
            retB = 0;
        } else if (B[i] == 2 && A[i] == 3) {
            retA++;
            retB = 0;
        } else if (B[i] == 3 && A[i] == 1) {
            retA++;
            retB = 0;
        } else if (B[i] == A[i]) {
            if (retA) {
                retA = 0;
                retB++;
            } else {
                retB = 0;
                retA++;
            }
        }
        ret = max({ret, retA, retB});
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

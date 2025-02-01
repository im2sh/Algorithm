#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, N, D, ret;
vector<int> W, H;
vector<int> RW, RH;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> R >> C;
    cin >> N;

    W.push_back(0);
    H.push_back(0);
    W.push_back(C);
    H.push_back(R);

    while (N--) {
        int d, n;
        cin >> d >> n;
        if (d)
            H.push_back(n);
        else
            W.push_back(n);
    }
    sort(W.begin(), W.end());
    sort(H.begin(), H.end());
}

void solve() {
    for (int i = 1; i < W.size(); i++) {
        RW.push_back(W[i] - W[i - 1]);
    }

    for (int i = 1; i < H.size(); i++) {
        RH.push_back(H[i] - H[i - 1]);
    }

    sort(RW.begin(), RW.end());
    sort(RH.begin(), RH.end());

    ret = RW[RW.size() - 1] * RH[RH.size() - 1];
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}


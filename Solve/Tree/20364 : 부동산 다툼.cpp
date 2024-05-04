#include <iostream>

using namespace std;
int N, Q, ret;
bool tree[1048577];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> Q;
}

void solve() {
    while (Q--) {
        int num;
        cin >> num;
        ret = 0;

        int temp = num;
        while (temp) {
            if (tree[temp])
                ret = temp;
            temp >>= 1;
        }
        if (!ret)
            tree[num] = true;
        cout << ret << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
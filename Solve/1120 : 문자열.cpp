#include <iostream>
#include <algorithm>

using namespace std;

string a, b;
int ret = 0x3f3f3f3f;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> a >> b;
}

void solve() {
    for (int i = 0; i <= b.size() - a.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < a.size(); j++) {
            if (a[j] != b[j + i])
                cnt++;
        }
        ret = min(ret, cnt);
    }
    cout << ret << '\n';
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

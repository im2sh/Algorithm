#include <iostream>
#include <set>

using namespace std;
int N, ret;
set<string> m;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    string temp;

    while (N--) {
        cin >> temp;

        if (temp == "ENTER") {
            ret += m.size();
            m.clear();
            continue;
        }

        m.insert(temp);
    }
    ret += m.size();

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int N, M, ret;
string s, temp, st;
unordered_set<string> MOS;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> s;
        MOS.insert(s);
    }
}

void solve() {
    while (M--) {
        cin >> temp;
        int pos = 0;
        while (pos < temp.length()) {
            int it = temp.find(',', pos);
            if (it == temp.npos) {
                st = temp.substr(pos);
                if (MOS.find(st) != MOS.end())
                    MOS.erase(st);
                break;
            } else {
                st = temp.substr(pos, it - pos);
                if (MOS.find(st) != MOS.end())
                    MOS.erase(st);
                pos = it + 1;
            }
        }
        cout << MOS.size() << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
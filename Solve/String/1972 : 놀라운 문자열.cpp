#include <iostream>
#include <set>

using namespace std;
string s;
bool flag;
set<string> D_Pair;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {

}

void solve() {
    while (true) {
        cin >> s;
        if (s == "*") {
            break;
        }
        flag = false;
        for (int i = 1; i < s.size(); i++) {
            if (flag)
                break;
            D_Pair.clear();
            int j = 0;
            int k = j + i;
            while (!flag && k < s.size()) {
                string temp;
                temp += s[j];
                temp += s[k];
                if (!D_Pair.empty()) {
                    if (D_Pair.find(temp) != D_Pair.end()) {
                        flag = true;
                        cout << s << " is NOT surprising.\n";
                        break;
                    }
                }
                D_Pair.insert(temp);
                j++;
                k++;
            }
        }
        if (!flag) {
            cout << s << " is surprising.\n";
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

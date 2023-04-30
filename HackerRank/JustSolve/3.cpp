#include <iostream>
#include <map>

using namespace std;

string s;
string programmer = "programmer";
map<char, int> pro_cnt;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> s;
}

void back_delete() {

}

void solve() {
    int idx = 0;
    map<char, int> temp;
    int cnt = 0;
    for (int i = 0; i < programmer.length(); i++) {
        pro_cnt[programmer[i]]++;
    }

    for (int i = 0; i < s.length(); i++) {
        temp[s[i]]++;
        if (temp[s[i]] == pro_cnt[s[i]]) {
            cnt++;
            if (cnt == 7) {
                idx = i;
                break;
            }
        }
    }

    s.erase(0, idx + 1);
    temp.clear();
    cnt = 0;

    for (int i = s.size() - 1; i >= 0; i--) {
        temp[s[i]]++;
        if (temp[s[i]] == pro_cnt[s[i]]) {
            cnt++;
            if (cnt == 7) {
                s.pop_back();
                break;
            }
        }
        s.pop_back();
    }

    cout << s.length();
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
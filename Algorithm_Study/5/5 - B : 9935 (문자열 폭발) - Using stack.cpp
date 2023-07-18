#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

string s;
string bomb;
stack<char> basket;
string ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> s;
    cin >> bomb;
}

void solve() {
    for (int i = 0; i < s.length(); i++) {
        string temp = "";
        basket.push(s[i]);
        int bsize = bomb.size();
        if (basket.size() >= bomb.size() && basket.top() == bomb[bomb.length() - 1]) {
            while (bsize--) {
                temp += basket.top();
                basket.pop();
            }

            reverse(temp.begin(), temp.end());
            if (temp == bomb) {
                continue;
            } else {
                for (int j = 0; j < temp.size(); j++) {
                    basket.push(temp[j]);
                }
            }
        }
    }
    if (!basket.size()) {
        cout << "FRULA" << "\n";
    } else {
        while (basket.size()) {
            ret += basket.top();
            basket.pop();
        }
        reverse(ret.begin(), ret.end());
        cout << ret << "\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}


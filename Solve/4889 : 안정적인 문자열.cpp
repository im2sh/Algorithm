#include <iostream>
#include <stack>

using namespace std;
string str;
int t = 1, ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    while (1) {
        cin >> str;
        if (str[0] == '-')
            break;
        ret = 0;
        stack<char> s;
        for (int i = 0; i < str.size(); i++) {
            char c = str[i];
            if (c == '}' && !s.empty() && s.top() == '{')
                s.pop();
            else
                s.push(c);
        }
        while (!s.empty()) {
            char c1 = s.top();
            s.pop();
            char c2 = s.top();
            s.pop();
            if (c1 == c2)
                ret++;
            else
                ret += 2;
        }
        cout << t << ". " << ret << '\n';
        t++;
    }
}

int main(void) {
    FastIO();
    solve();
    return 0;
}
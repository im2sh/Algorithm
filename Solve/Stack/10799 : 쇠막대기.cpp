#include <iostream>
#include <stack>

using namespace std;

int ret;
string s;
stack<char> st;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> s;
}

void solve() {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push('(');
        } else {
            if (s[i - 1] == '(') {
                ret += st.size() - 1;
                st.pop();
            } else {
                st.pop();
                ret++;
            }
        }
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
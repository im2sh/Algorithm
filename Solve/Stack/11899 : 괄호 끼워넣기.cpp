#include <iostream>
#include <stack>

using namespace std;

int ret;
string S;
stack<char> st;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> S;
}

void solve() {
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '(') {
            st.push(S[i]);
        } else {
            if (st.size() && st.top() == '(') {
                st.pop();
            } else {
                ret++;
            }
        }
    }
    ret += st.size();
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
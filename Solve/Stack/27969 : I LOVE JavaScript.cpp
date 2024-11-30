#include <iostream>
#include <stack>

using namespace std;

typedef long long ll;

stack<ll> st;
string S;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
}

void solve() {
    while (cin >> S) {
        if (S == "[") {
            st.push(0);
        } else if (isdigit(S[0])) {
            st.push(8);
        } else if (S == "]") {
            ll temp = 0;
            while (st.top() != 0) {
                temp += st.top();
                st.pop();
            }
            st.pop();
            st.push(temp + 8);
        } else {
            st.push(S.size() + 12);
        }
    }
    cout << st.top();
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
#include <iostream>
#include <stack>

using namespace std;

string S;
stack<char> st;
int ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> S;
}

void solve() {
    int temp = 1;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '(') {
            temp *= 2;
            st.push(S[i]);
        } else if (S[i] == '[') {
            temp *= 3;
            st.push(S[i]);
        } else if (S[i] == ')' && !st.empty()) {
            if (st.top() == '(') {
                if (S[i - 1] == '(') {
                    ret += temp;
                }
                st.pop();
                temp /= 2;
            } else {
                cout << "0";
                return;
            }
        } else if (S[i] == ']' && !st.empty()) {
            if (st.top() == '[') {
                if (S[i - 1] == '[') {
                    ret += temp;
                }
                st.pop();
                temp /= 3;
            } else {
                cout << "0";
                return;
            }
        } else if (st.empty() && (S[i] == ']' || S[i] == ')')) {
            cout << "0";
            return;
        }
        if (st.size() == 0)
            temp = 1;
    }
    if (st.size())
        ret = 0;
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
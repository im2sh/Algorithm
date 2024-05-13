#include <iostream>
#include <stack>

using namespace std;

string S;
int ret;
stack<int> st;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> S;
}

void solve() {
    string temp = "";
    int length = 0;;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '(')
            st.push(-1);
        else if (isdigit(S[i])) {
            if (S[i + 1] == '(')
                st.push(S[i] - '0');
            else
                st.push(1);
        } else {
            int len = 0;
            while (st.size()) {
                if (st.top() == -1) {
                    st.pop();
                    break;
                } else {
                    len += st.top();
                }
                st.pop();
            }
            len *= st.top();
            st.pop();
            st.push(len);
        }
    }

    while (st.size()) {
        ret += st.top();
        st.pop();
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
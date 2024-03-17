#include <iostream>
#include <stack>

using namespace std;

string str;
int ret;
stack<int> st;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> str;
}

void solve() {
    int temp = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            st.push(-1);
        } else if (str[i] == 'H') {
            st.push(1);
        } else if (str[i] == 'C') {
            st.push(12);
        } else if (str[i] == 'O') {
            st.push(16);
        } else if (str[i] >= '2' && str[i] <= '9') {
            temp = st.top() * (str[i] - '0');
            st.pop();
            st.push(temp);
        } else if (str[i] == ')') {
            int num = 0;
            while (st.top() != -1) {
                num += st.top();
                st.pop();
            }
            st.pop();
            st.push(num);
        }
    }
    while (!st.empty()) {
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
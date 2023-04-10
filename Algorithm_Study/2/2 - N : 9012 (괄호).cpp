#include <iostream>
#include <stack>

using namespace std;

int N;
string s;
stack<char> g;
bool flag = true;

void InitStack() {
    while (!g.empty())
        g.pop();
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s;
        flag = false;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '(')
                g.push(s[j]);
            else if (s[j] == ')' && !g.empty()) {
                g.pop();
                flag = true;
            } else {
                flag = false;
                break;
            }
        }
        if (!g.empty()) {
            flag = false;
            InitStack();
        }
        if (flag)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}
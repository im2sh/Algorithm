#include <iostream>
#include <string>
#include <stack>

using namespace std;

string s;
string result = "";

void FastIO() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void Init() {
    cin >> s;
}

string solve() {
    int size = s.size() - 1;
    stack<char> temp;
    temp.push(s[size]);
    while (size--) {
        if (temp.size() && temp.top() == s[size])
            temp.pop();
        else
            temp.push(s[size]);
    }


    while (temp.size()) {
        result += temp.top();
        temp.pop();
    }
    if (!result.size())
        return "Empty String";
    return result;
}

int main(void) {
    FastIO();
    Init();
    cout << solve();
    return 0;
}

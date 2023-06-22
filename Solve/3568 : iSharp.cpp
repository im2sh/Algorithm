#include <iostream>
#include <stack>

using namespace std;

string s;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    getline(cin, s);
}

string go(stack<char> *t) {
    string temp;
    while (t->size()) {
        if (t->top() == ']') {
            t->pop();
            continue;
        } else if (t->top() == '[') {
            t->pop();
            temp += "[]";
            continue;
        }

        temp += t->top();
        t->pop();
    }
    return temp;
}


void solve() {
    string temp = "";
    string common = "";
    stack<char> ts;
    int size;
    for (size = 0; size < s.length(); size++) {
        if (s[size] == ' ') {
            break;
        }
        common += s[size];
    }

    for (int i = size; i < s.length(); i++) {
        if (s[i] == ' ')
            continue;
        if (s[i] == ',' || s[i] == ';') {
            cout << common + go(&ts) + " " + temp + ";" << "\n";
            temp = "";

        } else {
            if (isalpha(s[i]))
                temp += s[i];
            else
                ts.push(s[i]);
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
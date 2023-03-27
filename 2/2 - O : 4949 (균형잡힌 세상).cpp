#include <iostream>
#include <stack>

using namespace std;

string sen;
string t;
stack<char> st;
char rightC;

bool checkS(stack<char> stk, string s) {
    for (char c: s) {
        if (c == '(' || c == '[') {
            stk.push(c);
            rightC = c;
        } else {
            if (!stk.empty() && ((stk.top() == '(' && c == ')') || (stk.top() == '[' && c == ']'))) {
                stk.pop();
            } else {
                return false;
            }
        }
    }
    return stk.empty();
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        getline(cin, sen);
        if (sen == ".")
            break;
        for (int i = 0; i < sen.size(); i++) {
            //if (!(65 <= sen[i] && sen[i] < 91 || 97 <= sen[i] && sen[i] < 122) && (sen[i] != ' ' && sen[i] != '.'))
            // 틀렸던 이유 : 알파벳만 고려했는데 다른 특수기호가 들어갈 수 있음
            if (sen[i] == '(' || sen[i] == ')' || sen[i] == '[' || sen[i] == ']')
                t.push_back(sen[i]);
        }
        if (checkS(st, t))
            cout << "yes" << "\n";
        else
            cout << "no" << "\n";
        t.erase(0, t.size());
    }
    return 0;
}
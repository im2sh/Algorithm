#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);

    for (int i = 0; i < s.size(); i++) {
        if (65 <= s[i] && s[i] < 78)
            s[i] = s[i] + 13;
        else if (78 <= s[i] && s[i] < 91)
            s[i] = s[i] - 13;
        else if (97 <= s[i] && s[i] < 110)
            s[i] = s[i] + 13;
        else if (110 <= s[i] && s[i] < 123)
            s[i] = s[i] - 13;
        else
            continue;
    }
    cout << s << "\n";
}

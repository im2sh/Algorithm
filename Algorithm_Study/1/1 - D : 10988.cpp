#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int end_char = s.size() - 1;
    bool result;

    for (int i = 0; i < s.size(); i++) {
        if (i / 2 == 1)
            break;
        if (s[i] == s[end_char])
            result = true;
        else {
            result = false;
            break;
        }
        end_char--;
    }
    if (result == true)
        cout << "1" << "\n";
    else
        cout << "0" << "\n";
}

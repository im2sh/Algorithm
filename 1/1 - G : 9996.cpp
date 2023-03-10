#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string find_s;
    string s;
    string left;
    string right;
    cin >> n;
    cin >> find_s;
    int pos = find_s.find('*');
    left = find_s.substr(0, pos);
    right = find_s.substr(pos + 1);

    for (int i = 0; i < n; i++) {
        cin >> s;
        if ((left.size() + right.size()) > s.size())
            cout << "NE" << "\n";
        else {
            if ((left == s.substr(0, left.size())) && (right == s.substr(s.size() - right.size())))

                cout << "DA" << "\n";
            else
                cout << "NE" << "\n";
        }
    }
}



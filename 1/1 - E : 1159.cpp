#include <iostream>
#include <vector>

using namespace std;
int alpha[26];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    bool flag = false;
    string player;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> player;
        alpha[player[0] - 97]++;
    }
    for (int i = 0; i < 26; i++) {
        if (alpha[i] > 4) {
            flag = true;
            cout << (char) (i + 97);
        }
    }
    if (flag == false)
        cout << "PREDAJA";
    return 0;
}

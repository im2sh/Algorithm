#include <iostream>

using namespace std;

string str;
int ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> str;
}

char go(char c) {
    if (c == 'Y')
        return 'N';
    else
        return 'Y';
}

void solve() {
    str = "x" + str;

    for (int i = 1; i < str.size(); i++) {
        if (str[i] == 'Y') {
            ret++;
            for (int j = i; j < str.size(); j++) {
                if (j % i != 0)
                    continue;
                str[j] = go(str[j]);
            }

        }
    }

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'Y') {
            ret = -1;
            break;
        }
    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
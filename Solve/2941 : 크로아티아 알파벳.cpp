#include <iostream>

using namespace std;
string alpha;
string ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> alpha;
}

int solve() {
    for (int i = 0; i < alpha.length(); i++) {
        if (alpha[i] == 'c' && (alpha[i] == '=' || alpha[i] == '-')) {
            ret += 'c';
            i += 1;
        } else if (alpha[i] == 'd' && (alpha[i + 1] == 'z' && alpha[i + 2] == '=')) {
            ret += 'd';
            i += 2;
        } else if (alpha[i] == 'd' && alpha[i + 1] == '-') {
            ret += 'd';
            i += 1;
        } else if (alpha[i] == 'l' && alpha[i + 1] == 'j') {
            ret += 'a';
            i += 1;
        } else if (alpha[i] == 'n' && alpha[i + 1] == 'j') {
            ret += 'a';
            i += 1;
        } else if (alpha[i] == 's' && alpha[i + 1] == '=') {
            ret += 'a';
            i += 1;
        } else if (alpha[i] == 'z' && alpha[i - 1] != 'd' && alpha[i + 1] == '=') {
            ret += 'a';
            i += 1;
        } else if (isalpha(alpha[i]))
            ret += alpha[i];
    }
    return ret.length();
}

int main(void) {
    FastIO();
    Init();
    cout << solve() << "\n";
    return 0;
}

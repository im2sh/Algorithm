#include <iostream>

using namespace std;

string alpha;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> alpha;
}

void solve() {
    for (int i = 0; i < alpha.size(); i++) {
        if ((i + 1) % 3 == 0)
            cout << "..*.";
        else
            cout << "..#.";
        if (i == alpha.size() - 1)
            cout << ".\n";
    }
    for (int i = 0; i < alpha.size(); i++) {
        if ((i + 1) % 3 == 0)
            cout << ".*.*";
        else
            cout << ".#.#";
        if (i == alpha.size() - 1)
            cout << ".\n";
    }
    for (int i = 0; i < alpha.size(); i++) {
        if (i > 0 && i % 3 == 0 || (i + 1) % 3 == 0)
            cout << "*";
        else
            cout << "#";
        if ((i + 1) % 3 == 0)
            cout << "." << alpha[i] << ".";
        else
            cout << "." << alpha[i] << ".";
        if (i == alpha.size() - 1) {
            if ((i + 1) % 3 == 0)
                cout << "*\n";
            else
                cout << "#\n";
        }
    }
    for (int i = 0; i < alpha.size(); i++) {
        if ((i + 1) % 3 == 0)
            cout << ".*.*";
        else
            cout << ".#.#";
        if (i == alpha.size() - 1)
            cout << ".\n";
    }
    for (int i = 0; i < alpha.size(); i++) {
        if ((i + 1) % 3 == 0)
            cout << "..*.";
        else
            cout << "..#.";
        if (i == alpha.size() - 1)
            cout << ".\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
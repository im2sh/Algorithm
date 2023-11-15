#include <iostream>
#include <list>

using namespace std;
int N;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    for (int i = 0; i < N; i++) {
        list<char> l;
        string s;
        cin >> s;
        auto cursor = l.begin();
        for (auto e: s) {
            if (e == '<') {
                if (cursor != l.begin())
                    cursor--;
            } else if (e == '>') {
                if (cursor != l.end())
                    cursor++;
            } else if (e == '-') {
                if (cursor != l.begin()) {
                    cursor--;
                    cursor = l.erase(cursor);
                }
            } else
                l.insert(cursor, e);

        }
        for (auto e: l)
            cout << e;
        cout << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

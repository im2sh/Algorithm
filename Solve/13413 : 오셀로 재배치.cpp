#include <iostream>
#include <algorithm>

using namespace std;

int N;
int num;
int w, b;
string x, y;

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
        cin >> num;
        w = 0;
        b = 0;
        cin >> x >> y;

        for (int i = 0; i < num; i++) {
            if (x[i] == y[i])
                continue;
            else {
                if (x[i] == 'B')
                    b++;
                else
                    w++;
            }
        }

        if (w > b)
            cout << w << '\n';
        else
            cout << b << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

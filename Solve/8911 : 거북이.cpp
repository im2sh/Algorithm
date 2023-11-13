#include <iostream>
#include <algorithm>

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};

int N;
string str;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    while (N--) {
        cin >> str;
        int cx = 0, cy = 0, cd = 0, minX = 0, maxX = 0, minY = 0, maxY = 0;
        for (int i = 0; i < str.size(); i++) {
            char c = str[i];
            if (c == 'L' || c == 'R') {
                if (c == 'L')
                    cd = (cd + 3) % 4;
                else
                    cd = (cd + 1) % 4;
            } else {
                if (c == 'F') {
                    cy += dy[cd];
                    cx += dx[cd];
                } else {
                    cy -= dy[cd];
                    cx -= dx[cd];
                }
                maxY = max(cy, maxY);
                maxX = max(cx, maxX);
                minY = min(cy, minY);
                minX = min(cx, minX);
            }
        }
        cout << (maxX - minX) * (maxY - minY) << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
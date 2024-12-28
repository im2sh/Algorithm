#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct menu {
    int A, B;
    int gap;
} Menu;

int N, X, ret;
vector<Menu> menus;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool cmp(Menu a, Menu b) {
    if (a.gap == b.gap)
        return a.A > b.A;
    return a.gap > b.gap;
}

void Init() {
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        menus.push_back({a, b, a - b});
    }
    sort(menus.begin(), menus.end(), cmp);
}

void solve() {
    for (int i = 0; i < N; i++) {
        int remainDay = N - i - 1;

        if (menus[i].gap <= 0) {
            ret += menus[i].B;
            X -= 1000;
        } else if (remainDay * 1000 <= X - 5000) {
            ret += menus[i].A;
            X -= 5000;
        } else {
            ret += menus[i].B;
            X -= 1000;
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
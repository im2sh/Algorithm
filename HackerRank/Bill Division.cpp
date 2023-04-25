#include <bits/stdc++.h>

using namespace std;

int n, k, b_charged, b_actual;
vector<int> bill;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        bill.push_back(temp);
    }
    cin >> b_charged;
}

void solve() {
    long long temp = 0;
    for (int i = 0; i < bill.size(); i++) {
        if (i == k)
            continue;
        temp += bill[i];
    }
    b_actual = temp / 2;

    if (b_actual == b_charged)
        cout << "Bon Appetit" << "\n";
    else
        cout << b_charged - b_actual << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

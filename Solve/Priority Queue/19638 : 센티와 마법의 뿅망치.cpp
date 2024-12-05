#include <iostream>
#include <queue>

using namespace std;

int N, H, T;
priority_queue<int, vector<int>, less<int>> people;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> H >> T;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        people.push(temp);
    }
}

void solve() {
    for (int i = 0; i < T; i++) {
        int h = people.top();

        if (h < H) {
            cout << "YES\n";
            cout << i << '\n';
            return;
        } else if (h > 1) {
            people.pop();
            people.push(h / 2);
        }
    }

    if (people.top() >= H)
        cout << "NO\n" << people.top();
    else
        cout << "YES\n" << T << '\n';
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
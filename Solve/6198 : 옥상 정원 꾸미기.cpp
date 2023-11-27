#include <iostream>
#include <stack>

using namespace std;

int N;
stack<int> building;
long long ret = 0;

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
        int height;
        cin >> height;

        if (building.empty()) {
            building.push(height);
            continue;
        }

        while (!building.empty() && building.top() <= height)
            building.pop();

        ret += building.size();

        building.push(height);
    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
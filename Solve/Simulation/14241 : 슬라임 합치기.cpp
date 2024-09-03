#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int N, ret;
vector<int> temp;
deque<int> slime;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        temp.emplace_back(t);
    }
    sort(temp.begin(), temp.end());
    for (int i = 0; i < N; i++) {
        slime.emplace_back(temp[i]);
    }
}

void solve() {
    while (true) {
        if (slime.size() == 1)
            break;
        int a = slime.front();
        slime.pop_front();
        int b = slime.front();
        slime.pop_front();
        ret += a * b;
        slime.push_front(a + b);
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

int N;

queue<ll> q;
vector<ll> v;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < 10; i++) {
        q.push(i);
        v.push_back(i);
    }
}

void solve() {
    int cnt = 0;
    while (q.size()) {
        ll temp = q.front();
        if (cnt == N) {
            cout << temp;
            return;
        }

        for (int i = 0; i < 10; i++) {
            if (temp % 10 > v[i]) {
                ll nextNum = (temp * 10) + v[i];
                q.push(nextNum);
            } else {
                break;
            }
        }
        q.pop();
        cnt++;
    }
    cout << "-1";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
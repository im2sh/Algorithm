#include <iostream>
#include <map>
#include <queue>

using namespace std;
int N;
map<string, int> MP;
queue<string> q;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string t1;
        int t2;
        cin >> t1 >> t2;
        MP[t1] = t2;
        q.push(t1);
    }
}

void solve() {
    while (q.size() > 1) {
        string student = q.front();
        q.pop();
        int cnt = MP[student];

        for (int i = 0; i < cnt - 1; i++) {
            string temp = q.front();
            q.pop();
            q.push(temp);
        }
        q.pop();
    }
    cout << q.front();
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
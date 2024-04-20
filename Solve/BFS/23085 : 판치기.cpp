#include <iostream>
#include <queue>

using namespace std;

typedef struct coin {
    int h, t, cnt;
} Coin;


int N, K;
int H, T;
bool visited[3001][3001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    string temp;
    cin >> N >> K;
    cin >> temp;
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == 'H')
            H++;
        else
            T++;
    }
}

void go() {
    queue<coin> q;
    q.push({H, T, 0});
    visited[H][T] = true;
    while (q.size()) {
        Coin coin = q.front();
        q.pop();
        if (coin.h == 0) {
            cout << coin.cnt;
            return;
        }

        for (int i = 1; i <= K; i++) {
            int front = coin.h - i;
            int back = coin.t - (K - i);
            if (front < 0 || back < 0)
                continue;
            int next_front = front + (K - i);
            int next_back = back + i;

            if (visited[next_front][next_back])
                continue;
            visited[next_front][next_back] = true;
            q.push({next_front, next_back, coin.cnt + 1});
        }
    }
    cout << "-1";
}

void solve() {
    go();
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
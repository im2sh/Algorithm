#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

typedef struct Info {
    int depth;
    string coins;
};

int TC, ret;
int coin[9];
int seq[8][3] = {{0, 1, 2},
                 {3, 4, 5},
                 {6, 7, 8},
                 {0, 3, 6},
                 {1, 4, 7},
                 {2, 5, 8},
                 {0, 4, 8},
                 {2, 4, 6}};
map<string, bool> dict;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    dict.clear();
    ret = 0;
    for (int i = 0; i < 9; i++) {
        char temp;
        cin >> temp;
        if (temp == 'H')
            coin[i] = 0;
        else
            coin[i] = 1;
    }
}

bool check(string stringCoin) {
    int coins[9];

    for (int i = 0; i < stringCoin.size(); i++) {
        coins[i] = stringCoin[i] - '0';
    }

    int oneCnt = 0;
    int zeroCnt = 0;
    for (int i = 0; i < 9; i++) {
        if (coins[i] == 0)
            zeroCnt++;
        else if (coins[i] == 1)
            oneCnt++;
    }
    if (oneCnt == 9 || zeroCnt == 9)
        return true;
    return false;
}

string changeCoinToString(int coins[9]) {
    string temp = "";
    for (int i = 0; i < 9; i++) {
        temp += to_string(coins[i]);
    }
    return temp;
}

void go() {
    queue<Info> q;
    string temp = changeCoinToString(coin);
    q.push({0, temp});
    while (q.size()) {
        int depth = q.front().depth;
        string coins = q.front().coins;
        if (check(coins)) {
            cout << depth << '\n';
            return;
        }
        q.pop();

        int coinArray[9];
        int nextCoinArray[9];
        for (int i = 0; i < 9; i++) {
            coinArray[i] = coins[i] - '0';
        }

        for (int i = 0; i < 8; i++) {
            memcpy(nextCoinArray, coinArray, sizeof(coinArray));
            for (int j = 0; j < 3; j++) {
                nextCoinArray[seq[i][j]] = !coinArray[seq[i][j]];
            }
            temp = changeCoinToString(nextCoinArray);
            if (dict[temp])
                continue;
            dict[temp] = true;
            q.push({depth + 1, temp});
        }
    }
    cout << -1 << '\n';
}

void solve() {
    while (TC--) {
        Input();
        go();
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
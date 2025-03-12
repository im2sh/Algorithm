#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct player {
    int num, A, B, C, sum, mul;
} Player;

int N;
vector<Player> players;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        Player p;
        cin >> p.num >> p.A >> p.B >> p.C;
        p.sum = p.A + p.B + p.C;
        p.mul = p.A * p.B * p.C;
        players.push_back(p);
    }
}

bool cmp(Player a, Player b) {
    if (a.mul == b.mul) {
        if (a.sum == b.sum)
            return a.num < b.num;
        return a.sum < b.sum;
    }
    return a.mul < b.mul;

}

void solve() {
    sort(players.begin(), players.end(), cmp);
    cout << players[0].num << " " << players[1].num << " " << players[2].num << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
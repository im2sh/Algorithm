#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;
int N, Hatk;
ll ret;
vector<pair<int, pair<int, int>>> dungeon;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b, c;
    cin >> N >> Hatk;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        dungeon.push_back({a, {b, c}});
    }
}

bool tryDungeon(ll mid) {
    ll maxHp = mid;
    ll curHp = mid;
    ll curAtk = Hatk;

    for (int i = 0; i < N; i++) {
        int type = dungeon[i].first;
        int secondInfo = dungeon[i].second.first;
        int thirdInfo = dungeon[i].second.second;

        if (type == 1) {
            ll enemyAttack = thirdInfo / curAtk;
            if (thirdInfo % curAtk == 0)
                enemyAttack--;
            curHp -= enemyAttack * secondInfo;
            if (curHp <= 0)
                break;
        } else {
            curAtk += secondInfo;
            curHp += thirdInfo;
            if (curHp > maxHp)
                curHp = maxHp;
        }
    }
    return curHp > 0;
}

void solve() {
    ll low = 1;
    ll high = 2e16;

    while (low <= high) {
        ll mid = (low + high) / 2;
        if (tryDungeon(mid)) {
            high = mid - 1;
            ret = mid;
        } else {
            low = mid + 1;
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
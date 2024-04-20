#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Info {
    int idx, hp;
} Info;

int X, Y, M, idx = 0;
int hp = 0;
vector<Info> enemy;
vector<Info> potion;
vector<int> ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool hpCmp(Info a, Info b) {
    return a.hp < b.hp;
}

bool enemyCmp(Info a, Info b) {
    return a.hp > b.hp;
}

void Init() {
    cin >> X >> Y >> M;
    for (int i = 0; i < X; i++) {
        int temp;
        cin >> temp;
        enemy.push_back({i + 1, temp});
    }

    for (int i = 0; i < Y; i++) {
        int temp;
        cin >> temp;
        potion.push_back({i + 1, temp});
    }
    hp = M;
    sort(enemy.begin(), enemy.end(), enemyCmp);
    sort(potion.begin(), potion.end(), hpCmp);
}

void solve() {
    for (int i = 0; i < X; i++) {
        if (hp <= 0)
            break;
        if (hp > enemy[i].hp) {
            hp -= enemy[i].hp;
            ret.push_back(enemy[i].idx - (enemy[i].idx * 2));
        } else {
            while (true) {
                if (idx == Y || hp > enemy[i].hp)
                    break;
                if (hp <= enemy[i].hp) {
                    hp += potion[idx].hp;
                    ret.push_back(potion[idx].idx);
                    idx++;
                    if (hp > M)
                        hp = M;
                }
            }
            hp -= enemy[i].hp;
            ret.push_back(enemy[i].idx - (enemy[i].idx * 2));
        }
    }
    while (true) {
        if (idx >= Y)
            break;
        ret.push_back(potion[idx].idx);
        idx++;
    }

    if (ret.size() != X + Y || hp <= 0)
        cout << "0";
    else {
        for (int i = 0; i < ret.size(); i++) {
            cout << ret[i] << '\n';
        }
    }

}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
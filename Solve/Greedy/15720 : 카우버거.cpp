#include <iostream>
#include <algorithm>

using namespace std;

int B, C, D, sum, ret;
vector<int> burger;
vector<int> side;
vector<int> drink;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool cmp(int a, int b) {
    return a > b;
}

void Init() {
    int temp;
    cin >> B >> C >> D;

    for (int i = 0; i < B; i++) {
        cin >> temp;
        burger.push_back(temp);
        sum += temp;
    }

    for (int i = 0; i < C; i++) {
        cin >> temp;
        side.push_back(temp);
        sum += temp;
    }
    for (int i = 0; i < D; i++) {
        cin >> temp;
        drink.push_back(temp);
        sum += temp;
    }

    sort(burger.begin(), burger.end(), cmp);
    sort(side.begin(), side.end(), cmp);
    sort(drink.begin(), drink.end(), cmp);
}

int go() {
    int temp = 0;
    int minNum = min(burger.size(), min(side.size(), drink.size()));

    for (int i = 0; i < minNum; i++) {
        temp += burger[i] * 0.9;
        temp += side[i] * 0.9;
        temp += drink[i] * 0.9;
    }

    for (int i = minNum; i < burger.size(); i++)
        temp += burger[i];
    for (int i = minNum; i < side.size(); i++)
        temp += side[i];
    for (int i = minNum; i < drink.size(); i++)
        temp += drink[i];
    return temp;
}

void solve() {
    cout << sum << '\n' << go();
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
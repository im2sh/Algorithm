#include <iostream>
#include <unordered_map>

using namespace std;
int N, P, W, L, G;
unordered_map<string, int> mp;
int score = 0;
bool flag = false;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> P;
    cin >> W >> L >> G;
    for (int i = 0; i < P; i++) {
        string name, result;
        cin >> name >> result;
        if (result == "W") {
            mp.insert(make_pair(name, W));
        } else if (result == "L") {
            mp.insert(make_pair(name, -L));
        }
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        if (mp.find(temp) != mp.end()) {
            score += mp[temp];
        } else {
            score -= L;
        }
        if (score < 0) {
            score = 0;
        } else if (score >= G) {
            flag = true;
        }
    }
    if (flag) {
        cout << "I AM NOT IRONMAN!!\n";
    } else {
        cout << "I AM IRONMAN!!\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
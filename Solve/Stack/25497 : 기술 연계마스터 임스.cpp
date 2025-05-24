#include <iostream>
#include <stack>

using namespace std;

int N, ret;
string skill;
stack<char> LR, SK;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    cin >> skill;
}

void solve() {
    for (int i = 0; i < skill.size(); i++) {
        if (skill[i] == 'L') {
            LR.push(skill[i]);
        } else if (skill[i] == 'S') {
            SK.push(skill[i]);
        } else if (skill[i] == 'K') {
            if (!SK.empty()) {
                ret++;
                SK.pop();
            } else {
                break;
            }
        } else if (skill[i] == 'R') {
            if (!LR.empty()) {
                ret++;
                LR.pop();
            } else {
                break;
            }
        } else {
            ret++;
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
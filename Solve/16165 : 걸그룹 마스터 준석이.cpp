#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int N, M;
map<string, vector<string>> group;
map<string, string> member;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string tempGroup;
        int tempN;
        cin >> tempGroup;
        cin >> tempN;
        for (int j = 0; j < tempN; j++) {
            string tempMember;
            cin >> tempMember;
            group[tempGroup].push_back(tempMember);
            member[tempMember] = tempGroup;
        }
        sort(group[tempGroup].begin(), group[tempGroup].end());

    }
}

void findGroup(string who) {
    cout << member[who] << '\n';
}

void findMember(string who) {
    for (auto &it: group[who]) {
        cout << it << '\n';
    }
}

void solve() {
    int choice;
    string who;
    for (int i = 0; i < M; i++) {
        cin >> who;
        cin >> choice;
        if (choice == 1)
            findGroup(who);
        else
            findMember(who);
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
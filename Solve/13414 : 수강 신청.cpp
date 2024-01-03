#include <iostream>
#include <unordered_map>

using namespace std;

int K, L;
unordered_map<string, int> student;
vector<pair<string, int>> ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    string temp;
    cin >> K >> L;
    for (int i = 0; i < L; i++) {
        cin >> temp;
        student[temp] = i;
    }
}

bool cmp(pair<string, int> &a, pair<string, int> &b) {
    return a.second < b.second;
}

void solve() {
    for (auto &it: student)
        ret.push_back(it);

    sort(ret.begin(), ret.end(), cmp);

    int size = min(K, (int) ret.size());

    for (int i = 0; i < size; i++)
        cout << ret[i].first << '\n';
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
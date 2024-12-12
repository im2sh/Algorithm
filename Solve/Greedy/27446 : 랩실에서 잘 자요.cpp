#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, M, last, ret;
map<int, bool> pages;
vector<int> lostPages;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        pages[temp] = true;
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {
        if (!pages[i])
            lostPages.push_back(i);
    }

    for (auto &it: lostPages) {
        if (last != 0)
            ret += min(7, (it - last) * 2);
        else
            ret += 7;
        last = it;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
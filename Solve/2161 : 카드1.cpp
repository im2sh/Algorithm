#include <iostream>
#include <deque>

using namespace std;
int N;
deque<int> card;
vector<int> ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        card.push_back(i);
    }
}

void solve() {
    while (card.size()) {
        ret.push_back(card.front());
        card.pop_front();

        int temp = card.front();
        card.pop_front();
        card.push_back(temp);
    }

    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
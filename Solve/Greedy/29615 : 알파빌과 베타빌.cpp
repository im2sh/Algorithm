#include <iostream>
#include <vector>

using namespace std;

int N, M, ret;
vector<int> people;
vector<int> waitingList;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        waitingList.push_back(temp);
    }

    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        people.push_back(temp);
    }
}

void solve() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if (waitingList[j] == people[i])
                ret++;
        }
    }
    cout << M - ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, ret;
vector<int> crane;
vector<int> box;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool cmp(int a, int b) {
    return a > b;
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        crane.push_back(temp);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        box.push_back(temp);
    }
    sort(crane.begin(), crane.end(), cmp);
    sort(box.begin(), box.end(), cmp);
}


void solve() {
    if (crane[0] < box[0]) {
        cout << -1;
        return;
    }
    while (box.size()) {
        ret++;
        for (int i = 0; i < crane.size(); i++) {
            for (int j = 0; j < box.size(); j++) {
                if (crane[i] >= box[j]) {
                    box.erase(box.begin() + j);
                    break;
                }
            }
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
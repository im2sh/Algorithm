#include <iostream>

using namespace std;

int N;
int ret = 0;
vector<int> color = {1, 2, 3};

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    sort(color.begin(), color.end());
}

void solve(int N) {
    if (N > 3) {
        for (int i = 0; i < N; i++) {
            color.push_back(i % 3);
        }
    }
    sort(color.begin(), color.end());

    do {
        for (auto &it: color)
            continue;
        ret++;
    } while (next_permutation(color.begin(), color.end()));

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve(N);
    return 0;
}
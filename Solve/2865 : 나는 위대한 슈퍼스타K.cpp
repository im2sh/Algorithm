#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

float ability[101][101];
int N, M, K, person;
float sum;
float maxNum;
vector<float> ab;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M >> K;

    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> person;
            cin >> ability[person][i];
        }
    }
}

bool cmp(float a, float b) {
    return a > b;
}

void solve() {
    for (int i = 1; i <= N; i++) {
        maxNum = *max_element(ability[i] + 1, ability[i] + M + 1);
        ab.push_back(maxNum);
    }

    sort(ab.begin(), ab.end(), cmp);

    for (int i = 0; i < K; i++) {
        sum += ab[i];
    }

    cout << fixed;
    cout.precision(1);
    cout << sum;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
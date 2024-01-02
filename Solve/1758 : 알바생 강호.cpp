#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<long long> tips;
long long ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        tips.push_back(temp);
    }
}

bool cmp(long long a, long long b) {
    return a > b;
}

void solve() {
    sort(tips.begin(), tips.end(), cmp);
    for (int i = 0; i < N; i++) {
        if (tips[i] - i > 0) {
            ret += tips[i] - i;
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

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;
int minNum = 2000000001;
int ret[2];

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
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
}

void solve() {
    int start = 0;
    int end = N - 1;
    while (start < end) {
        int sum = v[start] + v[end];

        if (minNum > abs(sum)) {
            ret[0] = v[start];
            ret[1] = v[end];

            minNum = abs(sum);
        }
        if (minNum == 0)
            break;

        if (sum < 0)
            start++;
        else
            end--;
    }

    cout << ret[0] << " " << ret[1];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
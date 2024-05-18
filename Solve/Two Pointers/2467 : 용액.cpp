#include <iostream>
#include <vector>

using namespace std;
int N;
vector<int> liquid;
int ret[2];
int minNum = 2000000001;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        liquid.push_back(temp);
    }
}

void solve() {
    int start = 0;
    int end = N - 1;

    while (start < end) {
        int sum = liquid[start] + liquid[end];
        if (minNum > abs(sum)) {
            minNum = abs(sum);
            ret[0] = liquid[start];
            ret[1] = liquid[end];
        }

        if (minNum == 0)
            break;
        if (sum < 0)
            start++;
        else
            end--;
    }
    cout << ret[0] << ' ' << ret[1];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

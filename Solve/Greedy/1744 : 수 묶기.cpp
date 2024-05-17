#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
int N;
ll ret;
vector<int> arr;
bool visited[51];

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
        arr.push_back(temp);
    }
}

bool cmp(int a, int b) {
    if (a <= 0 || b <= 0)
        return a > b;

    return a < b;
}

void solve() {
    sort(arr.begin(), arr.end(), cmp);

    for (int i = N - 1; i > 0; i--) {
        if (visited[i])
            continue;
        int sum = arr[i] + arr[i - 1];
        int mul = arr[i] * arr[i - 1];
        if (mul > sum) {
            ret += mul;
            visited[i] = true;
            visited[i - 1] = true;
        } else {
            visited[i] = true;
            ret += arr[i];
        }
    }
    if (!visited[0])
        ret += arr[0];
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
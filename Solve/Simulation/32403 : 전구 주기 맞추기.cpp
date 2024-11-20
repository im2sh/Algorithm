#include <iostream>
#include <vector>

using namespace std;

int N, T, ret;
vector<int> arr;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
}

int go(int start) {
    if (T % start == 0)
        return 0;
    int nowPlus = start + 1;
    int nowMinus = start - 1;

    int cnt = 1;
    while (true) {
        if (T % nowPlus == 0 || T % nowMinus == 0)
            return cnt;
        nowPlus++;
        nowMinus--;
        cnt++;
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        ret += go(arr[i]);
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
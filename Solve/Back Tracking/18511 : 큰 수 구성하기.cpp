#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string N;
int K, ret;
string result;
vector<int> arr;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
}

void go() {
    if (result.length() > 0 && stoi(N) >= stoi(result)) {
        ret = max(ret, stoi(result));
    }
    if (result.length() == N.length()) {
        return;
    }

    for (int i = 0; i < arr.size(); i++) {
        result += to_string(arr[i]);
        go();
        result.pop_back();
    }
}

void solve() {
    go();
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, ret;
vector<string> arr;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
}

bool go(string target) {
    int low = 0;
    int high = N - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid][0] == target[0]) {
            if (arr[mid].substr(0, target.size()) == target)
                return true;
        }
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

void solve() {
    for (int i = 0; i < M; i++) {
        string target;
        cin >> target;
        ret += go(target);
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
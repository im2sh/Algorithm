#include <iostream>
#include <vector>

using namespace std;

constexpr int line[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

string A, B;
vector<int> arr;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> A >> B;
    for (int i = 0; i < A.size(); i++) {
        arr.push_back(line[A[i] - 'A']);
        arr.push_back(line[B[i] - 'A']);
    }
}

void solve() {
    while (true) {
        vector<int> ret;
        for (int i = 0; i < arr.size() - 1; i++) {
            ret.push_back((arr[i] + arr[i + 1]) % 10);
        }

        arr = ret;
        if (arr.size() == 2) {
            cout << arr[0] << arr[1];
            return;
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
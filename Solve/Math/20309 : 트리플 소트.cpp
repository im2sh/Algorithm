#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr;
bool flag = true;

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

void solve() {
    for (int i = 0; i < N; i++) {
        if (i % 2 == arr[i] % 2) {
            flag = false;
        }
    }

    cout << (flag ? "YES" : "NO");
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
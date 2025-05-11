#include <iostream>

using namespace std;

int N;
int arr[101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

int euclidean(int a, int b) {
    int r = a % b;

    if (r == 0)
        return b;
    return
            euclidean(b, r);
}


void solve() {
    for (int i = 1; i < N; i++) {
        int e = euclidean(arr[0], arr[i]);
        cout << arr[0] / e << "/" << arr[i] / e << "\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
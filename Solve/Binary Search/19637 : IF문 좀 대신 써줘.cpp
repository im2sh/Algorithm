#include <iostream>

using namespace std;

int N, M;
int power[100004];
string title[100004];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> title[i] >> power[i];
}

int go(int target) {
    int mid = 0;
    int low = 0;
    int high = N - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (target <= power[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (target > power[mid])
        return mid + 1;
    else
        return mid;
}

void solve() {
    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        cout << title[go(temp)] << "\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
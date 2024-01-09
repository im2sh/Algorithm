#include <iostream>
#include <algorithm>

using namespace std;

int T, N, M, low, high;
vector<int> A;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> T;
}

void VInit() {
    int temp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        A.push_back(temp);
    }
    sort(A.begin(), A.end());
    cin >> M;
}

bool search(int target) {
    low = 0;
    high = N - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (A[mid] == target)
            return true;
        else if (target < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}

void solve() {
    int target = 0;
    for (int i = 0; i < T; i++) {
        A.clear();
        VInit();
        for (int i = 0; i < M; i++) {
            cin >> target;
            if (search(target))
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
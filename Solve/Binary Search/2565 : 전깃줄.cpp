#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> line;
int lis[101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool cmp(pair<int, int> A, pair<int, int> B) {
    return A.first < B.first;
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        line.push_back({A, B});
    }
    sort(line.begin(), line.end(), cmp);
}

int go(int low, int high, int target) {
    while (low < high) {
        int mid = (low + high) / 2;

        if (lis[mid] < target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return high;
}

void solve() {
    int i = 1;
    int j = 0;
    lis[0] = line[0].second;

    while (i < N) {
        if (lis[j] < line[i].second) {
            lis[j + 1] = line[i].second;
            j++;
        } else {
            int idx = go(0, j, line[i].second);
            lis[idx] = line[i].second;
        }
        i++;
    }
    cout << N - (j + 1);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
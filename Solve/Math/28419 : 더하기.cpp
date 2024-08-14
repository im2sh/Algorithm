#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

int N;
ll odd, even;
vector<int> arr;

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
        if (i % 2 == 0)
            odd += arr[i];
        else
            even += arr[i];
    }
    if (N == 3 && odd > even)
        cout << "-1";
    else
        cout << abs(odd - even);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
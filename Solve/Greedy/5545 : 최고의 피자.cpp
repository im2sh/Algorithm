#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, A, B, C, ret, price, cal;
vector<int> arr;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool cmp(int a, int b) {
    return a > b;
}

void Init() {
    cin >> N >> A >> B >> C;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end(), cmp);
}

void solve() {
    int dough = C / A;
    ret = dough;
    price = A;
    cal = C;

    for (int i = 0; i < N; i++) {
        price += B;
        cal += arr[i];

        if (ret < cal / price)
            ret = cal / price;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
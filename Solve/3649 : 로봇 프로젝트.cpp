#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int X, N;
vector<int> v;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    while (cin >> X >> N) {
        int temp;
        int low = 0;
        int high = 0;
        bool flag = false;
        X *= 10000000;
        v.clear();

        for (int i = 0; i < N; i++) {
            cin >> temp;
            v.push_back(temp);
        }
        sort(v.begin(), v.end());
        high = v.size() - 1;
        while (low < high) {
            int sum = v[low] + v[high];
            if (sum == X) {
                flag = true;
                break;
            }
            if (sum < X) {
                low++;
            } else {
                high--;
            }
        }
        if (flag)
            cout << "yes " << v[low] << ' ' << +v[high] << '\n';
        else
            cout << "danger" << '\n';
    }
}

int main() {
    FastIO();
    solve();
    return 0;
}
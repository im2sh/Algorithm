#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

ll N, C;
bool flag = false;
vector<ll> arr;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    ll temp;
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
}

void solve() {
    for (int i = 0; i < N; i++) {
        if (arr[i] == C) {
            flag = true;
            break;
        }
        for (int j = i + 1; j < N; j++) {
            ll sum = arr[i] + arr[j];
            if (sum == C) {
                flag = true;
                break;
            } else {
                int low = j + 1;
                int high = N;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    ll tempSum = sum + arr[mid];
                    if (tempSum == C) {
                        flag = true;
                        break;
                    } else if (tempSum < C) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            }
            if (flag)
                break;
        }
        if (flag)
            break;
    }
    if (flag)
        cout << "1";
    else
        cout << "0";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
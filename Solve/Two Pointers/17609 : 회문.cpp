#include <iostream>

using namespace std;

int N;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

int go(string S) {
    int low = 0;
    int high = S.length() - 1;

    while (low <= high) {
        if (S[low] == S[high]) {
            low++;
            high--;
        } else {
            int low1 = low + 1;
            int high1 = high;
            int cnt1 = 0;
            while (low1 <= high1) {
                if (S[low1] == S[high1]) {
                    low1++;
                    high1--;
                } else {
                    cnt1++;
                    low1++;
                    high1--;
                }
            }

            int low2 = low;
            int high2 = high - 1;
            int cnt2 = 0;
            while (low2 <= high2) {
                if (S[low2] == S[high2]) {
                    low2++;
                    high2--;
                } else {
                    cnt2++;
                    low2++;
                    high2--;
                }
            }
            if (cnt1 == 0 || cnt2 == 0)
                return 1;
            else
                return 2;
        }
    }
    return 0;
}

void solve() {
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        cout << go(S) << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
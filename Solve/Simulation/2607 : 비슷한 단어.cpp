#include <iostream>

using namespace std;
int N, ret;
string base;
int alpha[26];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    cin >> base;

    for (int i = 0; i < base.size(); i++) {
        alpha[base[i] - 'A'] += 1;
    }
}

void solve() {
    for (int i = 0; i < N - 1; i++) {
        string temp;
        cin >> temp;
        int copy_arr[26];
        copy(alpha, alpha + 26, copy_arr);

        int same = 0;
        for (int j = 0; j < temp.size(); j++) {
            if (copy_arr[temp[j] - 'A'] > 0) {
                copy_arr[temp[j] - 'A']--;
                same++;
            }
        }

        if (base.size() == temp.size()) {
            if (same == base.size() || same == base.size() - 1) {
                ret++;
            }
        } else if (base.size() - 1 == temp.size() && same == base.size() - 1) {
            ret++;
        } else if (base.size() + 1 == temp.size() && same == base.size()) {
            ret++;
        } else {
            continue;
        }
    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

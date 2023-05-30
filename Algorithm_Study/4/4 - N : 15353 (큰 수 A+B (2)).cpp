#include <iostream>

using namespace std;

string A, B;
int result[10005];
int sum;
string ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> A >> B;
}

void solve() {
    while (A.size() || B.size() || sum) {
        if (A.size()) {
            sum += A.back() - '0';
            A.pop_back();
        }
        if (B.size()) {
            sum += B.back() - '0';
            B.pop_back();
        }
        ret += (sum % 10) + '0';
        sum /= 10;
    }
    reverse(ret.begin(), ret.end());
}

int main(void) {
    FastIO();
    Init();
    solve();
    cout << ret << "\n";
    return 0;
}
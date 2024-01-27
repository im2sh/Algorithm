#include <iostream>
#include <string>

using namespace std;
string number;
int ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> number;
}

void solve() {
    while (int(number.size()) != 1) {
        int sum = 0;
        for (unsigned i = 0; i < number.size(); i++) {
            sum += int(number[i]) - 48;
        }
        number = to_string(sum);
        ret++;
    }
    cout << ret << '\n';
    if (number == "3" || number == "6" || number == "9")
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
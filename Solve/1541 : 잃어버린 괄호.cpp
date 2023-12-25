#include <iostream>

using namespace std;

string sentense;
int ret;
bool isMinus = false;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> sentense;
}

void solve() {
    string num;
    for (int i = 0; i <= sentense.size(); i++) {
        if (sentense[i] == '-' || sentense[i] == '+' || i == sentense.size()) {
            if (isMinus) {
                ret -= stoi(num);
                num = "";
            } else {
                ret += stoi(num);
                num = "";
            }
        } else {
            num += sentense[i];
        }

        if (sentense[i] == '-') {
            isMinus = true;
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
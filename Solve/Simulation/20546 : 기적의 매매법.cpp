#include <iostream>
#include <vector>

using namespace std;

int jun, sung; // 준현과 성민이가 가진돈
int junRet, sungRet; // 준현과 성민이의 보유 주식
vector<int> money;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> temp;
    jun = temp, sung = temp;
    for (int i = 0; i < 14; i++) {
        cin >> temp;
        money.push_back(temp);
    }
}

void solve() {
    for (int i = 0; i < 14; i++) {
        // 준현이 로직
        junRet += jun / money[i];
        jun -= (jun / money[i]) * money[i];
    }
    int up = 0;
    int down = 0;
    for (int i = 1; i < 14; i++) {
        if (money[i] > money[i - 1]) {
            up++;
            down = 0;
        } else if (money[i] < money[i - 1]) {
            down++;
            up = 0;
        }

        if (down >= 3) {
            sungRet += sung / money[i];
            sung -= (sung / money[i]) * money[i];
        } else if (up >= 3) {
            sung += sungRet * money[i];
            sungRet = 0;
        }
    }

    if (jun + (junRet * money[13]) > sung + (sungRet * money[13])) {
        cout << "BNP";
    } else if (jun + (junRet * money[13]) < sung + (sungRet * money[13])) {
        cout << "TIMING";
    } else {
        cout << "SAMESAME";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
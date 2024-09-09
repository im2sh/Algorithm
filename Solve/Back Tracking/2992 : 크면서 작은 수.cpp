#include <iostream>
#include <algorithm>

using namespace std;

int ret = 987654321;
string number;
int num;
bool visited[7];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> number;
    num = stoi(number);
}

void go(int depth, string N) {
    if (depth == number.length()) {
        int temp = stoi(N);
        if (number != N && num < temp)
            ret = min(ret, temp);
        return;
    }

    for (int i = 0; i < number.length(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            go(depth + 1, N + number[i]);
            visited[i] = false;
        }
    }
}

void solve() {
    string temp = "";
    go(0, temp);
    if (ret == 987654321)
        cout << "0";
    else
        cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
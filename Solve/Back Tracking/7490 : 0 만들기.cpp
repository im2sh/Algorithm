#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int TC, N;
int arr[10];
vector<string> ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
    for (int i = 1; i <= 9; i++) {
        arr[i] = i;
    }
}

bool check(string temp) {
    string tempNum;
    int sum = 0;
    vector<int> num;
    vector<int> op;
    for (int i = 0; i < temp.length(); i++) {
        if (temp[i] == '+' || temp[i] == '-') {
            op.push_back(temp[i]);
            num.push_back(stoi(tempNum));
            tempNum = "";
        } else {
            if (temp[i] == ' ') {
                tempNum += temp[++i];
            } else {
                tempNum += temp[i];
            }
        }
    }
    num.push_back(stoi(tempNum));
    sum = num[0];
    for (int i = 1; i < num.size(); i++) {
        if (op[i - 1] == '+')
            sum += num[i];
        else
            sum -= num[i];
    }
    if (sum == 0)
        return true;
    return false;
}

void go(int depth, string temp) {
    if (depth == N + 1) {
        if (check(temp))
            ret.push_back(temp);
        return;
    }
    go(depth + 1, temp + "+" + to_string(arr[depth]));
    go(depth + 1, temp + "-" + to_string(arr[depth]));
    go(depth + 1, temp + " " + to_string(arr[depth]));
}

void solve() {
    while (TC--) {
        ret.clear();
        string temp = to_string(arr[1]);
        cin >> N;
        go(2, temp);
        sort(ret.begin(), ret.end());
        for (int i = 0; i < ret.size(); i++) {
            cout << ret[i] << '\n';
        }
        cout << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
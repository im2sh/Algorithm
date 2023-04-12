#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
string S;

vector<int> num;
vector<char> op;
int ret = -987654321;

int calcu(char a, int b, int c) {
    if (a == '+') return b + c;
    if (a == '-') return b - c;
    if (a == '*') return b * c;
}

void solve(int here, int _num) {
    //cout << here << ":" << _num << "\n";
    if (here == num.size() - 1) {
        ret = max(ret, _num);
        return;
    }
    solve(here + 1, calcu(op[here], _num, num[here + 1]));

    if (here + 2 <= num.size() - 1) {
        int temp = calcu(op[here + 1], num[here + 1], num[here + 2]);
        solve(here + 2, calcu(op[here], _num, temp));
    }
    return;
}

void Init() {
    cin >> N;
    cin >> S;

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0)
            num.push_back(S[i] - '0');
        else
            op.push_back(S[i]);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Init();
    solve(0, num[0]);
    cout << ret << "\n";
    return 0;
}

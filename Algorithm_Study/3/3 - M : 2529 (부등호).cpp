#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> op;
int N;
int visited[10];
vector<string> ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    char temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        op.push_back(temp);
    }
}

bool cmp(char a, char b, char op) {
    if (a < b && op == '<')
        return true;
    if (a > b && op == '>')
        return true;
    return false;
}

void solve(int idx, string num) {
    if (idx == N + 1) {
        ret.push_back(num);
        return;
    }
    for (int i = 0; i <= 9; i++) {
        if (visited[i])
            continue;
        if (idx == 0 || cmp(num[idx - 1], i + '0', op[idx - 1])) {
            visited[i] = 1;
            solve(idx + 1, num + to_string(i));
            visited[i] = 0;
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve(0, "");
    sort(ret.begin(), ret.end());
    cout << ret[ret.size() - 1] << "\n" << ret[0] << "\n";
    return 0;
}

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int TC, cnt;
string S;
int visited[30];
bool flag = false;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    memset(visited, 0, sizeof(visited));
    cnt = 0;
    flag = false;
    for (int i = 0; i < 4; i++) {
        cin >> S;
        int temp = S[0] - '0';

        if (S[1] == 'p')
            temp += 10;
        else if (S[1] == 's')
            temp += 20;
        visited[temp]++;
    }
}

void solve() {
    while (TC--) {
        Input();
        for (int i = 0; i < 28; i++) {
            if (visited[i] && visited[i + 1] && visited[i + 2])
                flag = true;
        }
        for (int i = 0; i < 30; i++) {
            if (visited[i] > 2)
                flag = true;
            else if (visited[i] == 2)
                cnt++;
        }
        if (cnt == 2)
            flag = true;

        if (flag)
            cout << ":)\n";
        else
            cout << ":(\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
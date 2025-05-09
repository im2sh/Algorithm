#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int arr[3001];
bool visited[3001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {

}

void Input() {
    memset(visited, false, 3001);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

void solve() {
    while (true) {
        cin >> N;
        if (cin.eof())
            break;
        Input();
        bool flag = true;

        for (int i = 0; i < N - 1; i++) {
            int diff = abs(arr[i] - arr[i + 1]);
            if (visited[diff] || !diff || diff >= N) {
                flag = false;
                break;
            }
            visited[diff] = true;
        }

        if (flag)
            cout << "Jolly\n";
        else
            cout << "Not jolly\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
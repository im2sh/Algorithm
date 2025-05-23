#include <iostream>
#include <algorithm>

using namespace std;

int N, R = 1;
string arr[21];
bool visited[21][21];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {

}

void Input() {
    fill(&arr[0], &arr[0] + 21, "");
    fill(&visited[0][0], &visited[0][0] + 21 * 21, false);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        for (int j = 1; j <= N; j++) {
            char temp;
            if (i == j)
                continue;
            cin >> temp;
            if (temp == 'N') {
                visited[i][j] = true;
            }
        }
    }
}

void solve() {
    while (true) {
        cin >> N;
        if (N == 0)
            return;

        Input();
        cout << "Group " << R << '\n';

        bool flag = false;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (visited[i][j]) {
                    int temp = 0;
                    if (i - j > 0)
                        temp = i - j;
                    else
                        temp = i - j + N + 1;
                    cout << arr[temp] << " was nasty about " << arr[i] << '\n';
                    flag = true;
                }
            }
        }
        if (!flag) {
            cout << "Nobody was nasty \n";
        }
        cout << '\n';
        R++;
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
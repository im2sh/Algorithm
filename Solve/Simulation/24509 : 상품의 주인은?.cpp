#include <iostream>
#include <algorithm>

using namespace std;

int N;
pair<int, int> scores[4][200001];
bool visited[200001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        for (int j = 0; j < 4; j++) {
            int temp;
            cin >> temp;
            scores[j][i] = {-temp, num};
        }
    }

    for (int i = 0; i < 4; i++) {
        sort(scores[i], scores[i] + N);
    }
}

void solve() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < N; j++) {
            int temp = scores[i][j].second;

            if (visited[temp])
                continue;

            visited[temp] = true;
            cout << temp << ' ';
            break;
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
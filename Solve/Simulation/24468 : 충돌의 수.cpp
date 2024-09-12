#include <iostream>
#include <vector>

using namespace std;

int L, N, T, ret;
pair<int, char> balls[101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> L >> N >> T;
    for (int i = 1; i <= N; i++) {
        int S;
        char C;
        cin >> S >> C;
        balls[i] = {S, C};
    }

}

void solve() {
    for (int time = 1; time <= T; time++) {
        vector<int> box[1001];

        for (int i = 1; i <= N; i++) {
            pair<int, char> ball = balls[i];
            int s = ball.first;
            int c = ball.second;
            if (c == 'R') {
                if (s == L)
                    balls[i] = {s - 1, 'L'};
                else
                    balls[i] = {s + 1, 'R'};
            } else {
                if (s == 0)
                    balls[i] = {1, 'R'};
                else
                    balls[i] = {s - 1, 'L'};
            }

            int temp = balls[i].first;
            box[temp].push_back(i);
            if (box[temp].size() == 2) {
                if (balls[box[temp][0]].second == 'L')
                    balls[box[temp][0]].second = 'R';
                else
                    balls[box[temp][0]].second = 'L';

                if (balls[box[temp][1]].second == 'L')
                    balls[box[temp][1]].second = 'R';
                else
                    balls[box[temp][1]].second = 'L';
                ret++;
            }
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
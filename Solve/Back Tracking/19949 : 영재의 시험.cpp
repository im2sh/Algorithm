#include <iostream>
#include <vector>

using namespace std;
int ret;
vector<int> score;
vector<int> result;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    for (int i = 0; i < 10; i++) {
        int temp;
        cin >> temp;
        result.push_back(temp);
    }
}

void go(int depth) {
    if (depth == 10) {
        bool flag = true;
        for (int i = 0; i < 8; i++) {
            if (score[i] == score[i + 1] && score[i + 1] == score[i + 2]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            int cnt = 0;
            for (int i = 0; i < 10; i++) {
                if (result[i] == score[i])
                    cnt++;
            }
            if (cnt >= 5)
                ret++;
        }
        return;
    }

    for (int i = 1; i <= 5; i++) {
        score.push_back(i);
        go(depth + 1);
        score.pop_back();
    }
}

void solve() {
    go(0);
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
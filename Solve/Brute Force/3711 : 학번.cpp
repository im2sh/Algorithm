#include <iostream>
#include <vector>

using namespace std;

int TC, N, ret;
vector<int> student;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    student.clear();
    ret = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        student.push_back(temp);
    }
}

void go() {
    while (true) {
        ret++;
        int cnt = 0;
        int reminder[100001] = {0,};

        for (int i = 0; i < N; i++) {
            reminder[student[i] % ret]++;
            if (reminder[student[i] % ret] > 1) {
                cnt++;
                break;
            }
        }
        if (cnt > 0)
            continue;
        else {
            cout << ret << '\n';
            break;
        }
    }
}

void solve() {
    while (TC--) {
        Input();
        go();
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
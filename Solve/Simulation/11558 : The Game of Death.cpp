#include <iostream>
#include <vector>

using namespace std;

int TC, N, ret;
vector<int> arr;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void solve() {
    for (int i = 0; i < TC; i++) {
        cin >> N;
        ret = 1;
        arr.clear();
        arr.push_back(0);
        for (int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }

        int ptr = arr[1];

        while (ptr != N && ret <= N) {
            ptr = arr[ptr];
            ret++;
        }

        if (ret > N)
            ret = 0;
        cout << ret << "\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
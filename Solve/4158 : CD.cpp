#include <iostream>
#include <unordered_map>

using namespace std;
int N, M, ret;
int cd1, cd2;
unordered_map<int, int> CD;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {

}

void solve() {
    while (1) {
        cin >> N >> M;
        if (!N && !M)
            break;

        ret = 0;
        CD.clear();

        for (int i = 0; i < N; i++) {
            cin >> cd1;
            CD[cd1] = 1;
        }

        for (int i = 0; i < M; i++) {
            cin >> cd2;
            if (CD[cd2])
                ret++;
        }

        cout << ret << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
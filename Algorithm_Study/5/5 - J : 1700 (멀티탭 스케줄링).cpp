#include <iostream>
#include <vector>

using namespace std;

int N, K;
int visited[101];
vector<int> tool;
vector<int> multi;
int ret, pos;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> temp;
        tool.push_back(temp);
    }
}

void solve() {
    for (int i = 0; i < K; i++) {
        if (!visited[tool[i]]) {
            if (N == multi.size()) {
                int future = 0;
                for (auto &it: multi) {
                    int now = 987654321;
                    for (int j = i + 1; j < K; j++) {
                        if (it == tool[j]) {
                            now = j;
                            break;
                        }
                    }
                    if (future < now) {
                        future = now;
                        pos = it;
                    }
                }
                ret++;
                visited[pos] = 0;
                multi.erase(find(multi.begin(), multi.end(), pos));
            }
            multi.push_back(tool[i]);
            visited[tool[i]] = 1;
        }
    }
    cout << ret << "\n";

}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
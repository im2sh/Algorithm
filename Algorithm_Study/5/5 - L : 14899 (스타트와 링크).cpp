#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int M[21][21];
int visited[21];
int ret = 987654321;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            cin >> M[y][x];
        }
    }
}

int cal_diff(vector<int> teamA, vector<int> teamB) {
    int diff1 = 0;
    int diff2 = 0;
    for (int i = 0; i < teamA.size(); i++) {
        for (int j = i + 1; j < teamA.size(); j++) {
            diff1 += M[teamA[i]][teamA[j]] + M[teamA[j]][teamA[i]];
            diff2 += M[teamB[i]][teamB[j]] + M[teamB[j]][teamB[i]];
        }
    }
    return abs(diff1 - diff2);
}

void solve(int depth, int start) {
    if (depth == N / 2) {
        vector<int> A;
        vector<int> B;
        for (int j = 1; j <= N; j++) {
            if (visited[j])
                A.push_back(j);
            else
                B.push_back(j);
        }
        ret = min(ret, cal_diff(A, B));
    }
    for (int i = start; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            solve(depth + 1, i + 1);
            visited[i] = 0;
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve(0, 1);
    cout << ret << "\n";
    return 0;
}

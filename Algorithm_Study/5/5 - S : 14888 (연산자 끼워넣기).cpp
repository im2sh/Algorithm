#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int A[101];
int temp[4];
vector<int> op;
vector<int> op_seq;
int visited[100];
int maxRet = -1000000000;
int minRet = 1000000000;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int cal(int prev, int next, int num) {
    switch (num) {
        case 0:
            return prev + next;
        case 1:
            return prev - next;
        case 2:
            return prev * next;
        case 3:
            return prev / next;
    }
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> temp[i];
    }
    for (int i = 0; i < 4; i++) {
        while (temp[i]) {
            op.push_back(i);
            temp[i]--;
        }
    }
}

void cal() {
    int minT = 0;
    int maxT = 0;
    int i = 0;
    int opcnt = 0;
    while (i < N) {
        if (i == 0) {
            minT = A[i];
            maxT = A[i];
            i++;
            continue;
        }
        minT = cal(minT, A[i], op_seq[opcnt]);
        maxT = cal(maxT, A[i], op_seq[opcnt]);
        i++;
        opcnt++;
    }

    minRet = min(minRet, minT);
    maxRet = max(maxRet, maxT);
}

void solve(int depth) {
    if (depth == N - 1) {
        cal();
        return;
    }

    for (int i = 0; i < N - 1; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            op_seq.push_back(op[i]);
            solve(depth + 1);
            op_seq.pop_back();
            visited[i] = 0;
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve(0);
    cout << maxRet << "\n";
    cout << minRet << "\n";
    return 0;
}
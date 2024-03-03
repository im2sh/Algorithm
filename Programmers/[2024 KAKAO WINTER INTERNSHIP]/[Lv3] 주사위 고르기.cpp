#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int N, ret = -1;
int result[5];
int visited[11];
vector<int> win;
vector<int> lose;

void goWin(vector<vector<int>> dice, vector<int> winCombi, int depth, int sum) {
    if (depth == N / 2) {
        win.push_back(sum);
        return;
    }
    for (int i = 0; i < 6; i++) {
        goWin(dice, winCombi, depth + 1, sum + dice[winCombi[depth]][i]);
    }
}

void goLose(vector<vector<int>> dice, vector<int> loseCombi, int depth, int sum) {
    if (depth == N / 2) {
        lose.push_back(sum);
        return;
    }
    for (int i = 0; i < 6; i++) {
        goLose(dice, loseCombi, depth + 1, sum + dice[loseCombi[depth]][i]);
    }
}

int go_binary_search() {
    int sum = 0;
    for (auto &target: win) {
        int low = 0;
        int high = lose.size();
        int mid = 0;
        while (low < high) {
            mid = (low + high) / 2;
            if (target > lose[mid])
                low = mid + 1;
            else
                high = mid;
        }
        sum += low;
    }
    return sum;
}

int processGame(vector<vector<int>> dice) {
    vector<int> winCombi;
    vector<int> loseCombi;
    for (int i = 0; i < N; i++) {
        if (visited[i])
            winCombi.push_back(i);
        else
            loseCombi.push_back(i);
    }
    goWin(dice, winCombi, 0, 0);
    goLose(dice, loseCombi, 0, 0);
    sort(win.begin(), win.end());
    sort(lose.begin(), lose.end());

    int sum = go_binary_search();

    win.clear();
    lose.clear();

    return sum;
}

void go(vector<vector<int>> dice, int idx, int depth) {
    if (depth == N / 2) {
        if (ret < processGame(dice)) {
            ret = processGame(dice);
            int idx = 0;

            for (int i = 0; i < N; i++) {
                if (visited[i]) {
                    result[idx++] = i + 1;
                }
            }
        }
        return;
    }

    for (int i = idx; i < N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            go(dice, i + 1, depth + 1);
            visited[i] = 0;
        }
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    N = dice.size();
    go(dice, 0, 0);

    for (int i = 0; i < N / 2; i++) {
        answer.push_back(result[i]);
    }
    return answer;
}
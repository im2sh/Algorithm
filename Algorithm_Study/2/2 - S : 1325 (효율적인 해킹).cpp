#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define SIZE 10001
using namespace std;

int N, M;
int n1, n2;
vector<int> computer[SIZE];
int visited[SIZE];
map<int, int> temp;
vector<int> result;
int cnt;

void dfs(int start) {
    visited[start] = true;

    for (int i = 0; i < computer[start].size(); i++) {
        int next = computer[start][i];
        if (!visited[next]) {
            cnt++;
            dfs(next);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int max = 0;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> n1 >> n2;
        computer[n2].push_back(n1);
    }

    for (int i = 1; i <= N; i++) {
        fill(&visited[0], &visited[0] + N + 1, 0);
        cnt = 0;
        dfs(i);
        temp[i] = cnt;
        if (cnt > max)
            max = cnt;
    }
    for (auto it: temp) {
        if (max == it.second)
            result.push_back(it.first);
    }

    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    return 0;
}
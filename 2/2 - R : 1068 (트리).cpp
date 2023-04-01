#include <iostream>
#include <vector>

#define SIZE 101
using namespace std;

vector<int> Tree[SIZE];
int N;
int deleteN;
int temp;
int rootIdx;
int totalCnt;
int cnt;

void dfs(int root) {
    bool isleaf = true;
    for (int i: Tree[root]) {
        if (i == deleteN) {
            continue;
        }
        isleaf = false;
        dfs(i);
    }
    if (isleaf) {
        totalCnt++;
        return;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp == -1)
            rootIdx = i;
        else
            Tree[temp].push_back(i);
    }

    cin >> deleteN;
    if (deleteN == rootIdx) {
        cout << "0" << "\n";
        return 0;
    }
    dfs(rootIdx);
    cout << totalCnt << "\n";
    return 0;l
}
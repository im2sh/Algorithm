#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int R, C, K;
int BOARD[101][101];
int tryCnt = 0;
int N, M;
vector<vector<int>> row;
vector<vector<int>> col;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> R >> C >> K;
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            cin >> BOARD[y][x];
        }
    }
    N = 3;
    M = 3;
}

bool check() {
    if (BOARD[R - 1][C - 1] == K)
        return false;
    return true;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

void rowCal() {
    vector<vector<pair<int, int>>> temp;
    map<int, int> m;
    for (int i = 0; i < row.size(); i++) {
        vector<pair<int, int>> tt;
        m.clear();
        for (int j = 0; j < row[i].size(); j++) {
            if (row[i][j] == 0)
                continue;
            m[row[i][j]]++;
        }
        for (auto &it: m) {
            tt.push_back({it.first, it.second});
        }
        temp.push_back(tt);
    }
    for (int i = 0; i < temp.size(); i++) {
        sort(temp[i].begin(), temp[i].end(), cmp);
    }
    int maxRow = 0;
    row.clear();

    for (int i = 0; i < temp.size(); i++) {
        vector<int> tr;
        row.push_back(tr);
        for (auto &it: temp[i]) {
            row[i].push_back(it.first);
            row[i].push_back(it.second);
        }
    }

    for (int i = 0; i < temp.size(); i++) {
        int size = row[i].size();
        maxRow = max(maxRow, size);
    }

    for (int i = 0; i < row.size(); i++) {
        int rowSize = row[i].size();
        if (row[i].size() == maxRow)
            continue;
        else {
            for (int j = 0; j < maxRow - rowSize; j++) {
                row[i].push_back(0);
            }
        }
    }

    N = row.size();
    M = row[0].size();

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            BOARD[y][x] = row[y][x];
        }
    }
}

void colCal() {
    vector<vector<pair<int, int>>> temp;
    map<int, int> m;
    for (int i = 0; i < col.size(); i++) {
        vector<pair<int, int>> tt;
        m.clear();
        for (int j = 0; j < col[i].size(); j++) {
            if (col[i][j] == 0)
                continue;
            m[col[i][j]]++;
        }
        for (auto &it: m) {
            tt.push_back({it.first, it.second});
        }
        temp.push_back(tt);
    }
    for (int i = 0; i < temp.size(); i++) {
        sort(temp[i].begin(), temp[i].end(), cmp);
    }
    int maxCol = 0;
    col.clear();

    for (int i = 0; i < temp.size(); i++) {
        vector<int> tr;
        col.push_back(tr);
        for (auto &it: temp[i]) {
            col[i].push_back(it.first);
            col[i].push_back(it.second);
        }
    }

    for (int i = 0; i < temp.size(); i++) {
        int size = col[i].size();
        maxCol = max(maxCol, size);
    }

    for (int i = 0; i < col.size(); i++) {
        int colSize = col[i].size();
        if (col[i].size() == maxCol)
            continue;
        else {
            for (int j = 0; j < maxCol - colSize; j++) {
                col[i].push_back(0);
            }
        }
    }

    N = col[0].size();
    M = col.size();

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            BOARD[y][x] = col[x][y];
        }
    }
}

void setUp() {
    row.clear();
    col.clear();

    for (int y = 0; y < N; y++) {
        vector<int> temp;
        for (int x = 0; x < M; x++) {
            temp.push_back(BOARD[y][x]);
        }
        row.push_back(temp);
    }

    for (int x = 0; x < M; x++) {
        vector<int> temp;
        for (int y = 0; y < N; y++) {
            temp.push_back(BOARD[y][x]);
        }
        col.push_back(temp);
    }
}

void go() {
    if (row.size() >= col.size()) {
        rowCal();
    } else {
        colCal();
    }
}

void solve() {
    while (check()) {
        setUp();
        go();
        tryCnt++;
        if (tryCnt > 100) {
            cout << -1;
            return;
        }
    }
    cout << tryCnt;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
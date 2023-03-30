#include <iostream>
#include <vector>
#include <algorithm>

#define SIZE 9

using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};


int mat[SIZE][SIZE];
vector<pair<int, int>> virus;
int N, M;
int visited[SIZE][SIZE];
int ret;
int cnt;

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if (ny < 0 || ny >= N || nx < 0 || nx >= M || mat[ny][nx] == 1)
            continue;
        else if (visited[ny][nx])
            continue;
        else {
            dfs(ny, nx);
        }
    }
}

void cntArea() {
    int maxCnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mat[i][j] == 0 && !visited[i][j])
                maxCnt++;
        }
    }
    if (ret < maxCnt)
        ret = maxCnt;
}

void makeOne(int a, int b) {
    if (cnt == 3) {
        for (int k = 0; k < virus.size(); k++) {
            dfs(virus[k].first, virus[k].second);
        }
        cntArea();
        fill(&visited[0][0], &visited[0][0] + SIZE * SIZE, 0);
    } else {
        for (int i = a; i < N; i++) {
            for (int j = b; j < M; j++) {
                if (mat[i][j] == 0) {
                    mat[i][j] = 1;
                    cnt++;
                    makeOne(a, b);
                    cnt--;
                    mat[i][j] = 0;
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 2)
                virus.push_back(make_pair(i, j));
        }
    }

    makeOne(0, 0);

    cout << ret << "\n";
    return 0;
}


//#include <iostream>
//#include <vector>
//#include <map>
//
//#define SIZE 8
//using namespace std;
//
//const int dy[4] = {-1, 0, 1, 0};
//const int dx[4] = {0, 1, 0, -1};
//
//int N, M;
//int arr[SIZE][SIZE];
//int original[SIZE][SIZE];
//int visited[SIZE][SIZE];
//int zerocnt;
//vector<int> maxCnt;
//
//void dfs(int y, int x) {
//    visited[y][x] = 1;
//    for (int i = 0; i < 4; i++) {
//        int ny = dy[i] + y;
//        int nx = dx[i] + x;
//
//        if (ny < 0 || ny >= N || nx < 0 || nx >= M || arr[ny][nx] == 1)
//            continue;
//        else if (!visited[ny][nx])
//            continue;
//        else
//            dfs(ny, nx);
//    }
//}
//
//int findzere() {
//    int cnt = 0;
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < M; j++) {
//            if (arr[i][j] == 0)
//                cnt++;
//        }
//    }
//    return cnt;
//}
//
//void initArr() {
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < M; j++) {
//            arr[i][j] = original[i][j];
//        }
//    }
//}
//
//int main(void) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    cin >> N >> M;
//
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < M; j++) {
//            cin >> arr[i][j];
//            original[i][j] = arr[i][j];
//        }
//    }
//
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < M; j++) {
//            if (arr[i][j] == 0) {
//                arr[i][j] = 1;
//                zerocnt++;
//            }
//
//            if (zerocnt == 3) {
//                for (int a = 0; a < N; a++) {
//                    for (int b = 0; b < M; b++)
//                        if (arr[a][b] == 2) {
//                            fill(&visited[0][0], &visited[0][0] + SIZE * SIZE, 0);
//                            dfs(a, b);
//                            cout << findzere << "\n";
//                            maxCnt.push_back(findzere());
//                            zerocnt = 0;
//                            initArr();
//                        }
//                }
//            }
//        }
//    }
//    sort(maxCnt.begin(), maxCnt.end());
//    cout << maxCnt[maxCnt.size()] << "\n";
//    return 0;
//}
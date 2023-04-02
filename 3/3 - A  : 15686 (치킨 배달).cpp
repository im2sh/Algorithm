#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define SIZE 54

using namespace std;

int N, M;
int where;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
int result = 987654321;

int caculateMin(vector<int> v) {
    int dis;
    int temp = 0;
    for (auto there: home) {
        int minDis = 987654321;
        for (int cnt: v) {
            dis = abs(there.first - chicken[cnt].first) + abs(there.second - chicken[cnt].second);
            minDis = min(minDis, dis);
        }
        temp += minDis;
    }
    return temp;
}

void selectChicken(int index, vector<int> v) {
    int temp;
    if (v.size() == M) {
        temp = caculateMin(v);
        result = min(result, temp);
        return;
    }
    for (int i = index; i < chicken.size(); i++) {
        v.push_back(i);
        selectChicken(i + 1, v);
        v.pop_back();
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> temp;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> where;
            if (where == 1)
                home.push_back({i, j});
            else if (where == 2)
                chicken.push_back({i, j});
        }
    }

    selectChicken(0, temp);
    cout << result << "\n";
    return 0;

}
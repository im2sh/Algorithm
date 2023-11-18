#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int tc, N, M;
vector<int> fee;
vector<int> weight;
queue<int> waitList;
int ret, where;
int area[101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> tc;
}

void input() {
    int temp = 0;
    fee.clear();
    weight.clear();
    fee.push_back(0);
    weight.push_back(0);
    ret = 0;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        fee.push_back(temp);
    }
    for (int i = 0; i < M; i++) {
        cin >> temp;
        weight.push_back(temp);
    }
}

int checkArea() {
    for (int i = 1; i <= N; i++) {
        if (area[i] == 0)
            return i;
    }
    return 0;
}


void inCar(int x) {
    int canPark = checkArea();
    if (!canPark) {
        waitList.push(x);
        return;
    }

    area[canPark] = x;
}

int whereCar(int x) {
    for (int i = 1; i <= N; i++) {
        if (area[i] == x)
            return i;
    }
}

void outCar(int x) {
    where = whereCar(x);
    ret += weight[x] * fee[where];

    area[where] = 0;

    if (waitList.size()) {
        area[where] = waitList.front();
        waitList.pop();
    }
}

void drive() {
    int temp = 0;
    for (int i = 0; i < 2 * M; i++) {
        cin >> temp;
        if (temp > 0) {
            inCar(temp);
        } else {
            outCar(abs(temp));
        }
    }
}

void solve() {
    for (int i = 1; i <= tc; i++) {
        input();
        drive();
        cout << '#' << i << ' ' << ret << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
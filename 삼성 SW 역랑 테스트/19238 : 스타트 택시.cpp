#include <iostream>
#include <queue>

using namespace std;
int N, M, fuel, tp;
pair<int, int> taxi;
int people[21][21];
int destination[21][21];
vector<pair<int, pair<int, int>>> deee;
int visited[21][21];
bool flag = true;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

void FastIO() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void Init() {
    int ty, tx, a, b, c, d;
    int temp;
    cin >> N >> M >> fuel;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> temp;
            if (temp == 1) {
                destination[y][x] = -1;
                people[y][x] = destination[y][x];
            }
        }
    }
    cin >> ty >> tx;
    taxi = {ty - 1, tx - 1};
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c >> d;
        people[a - 1][b - 1] = i + 1;
        destination[c - 1][d - 1] = i + 1;
        deee.push_back({i + 1, {c - 1, d - 1}});
    }
}

void displayPeople() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cout << people[y][x] << " ";
        }
        cout << "\n";
    }
}

void displayDes() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cout << destination[y][x] << " ";
        }
        cout << "\n";
    }
}

void takePeople(pair<int, int> t) {
    int cy = taxi.first;
    int cx = taxi.second;
    int target = 987654321;
    queue<pair<int, int>> q;
    q.push({cy, cx});
    visited[cy][cx] = 1;
    while (q.size()) {
        cy = q.front().first;
        cx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || people[ny][nx] == -1)
                continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[cy][cx] + 1;
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (people[y][x] == -1 || people[y][x] == 0)
                continue;
            if (visited[y][x] < target) {
                taxi = {y, x};
                target = visited[y][x];
                tp = people[y][x];
            }
        }
    }
    if (visited[taxi.first][taxi.second] == 0) {
        flag = false;
        return;
    }
    fuel = fuel - (visited[taxi.first][taxi.second] - 1);
    people[taxi.first][taxi.second] = 0;
    if (fuel <= 0) {
        flag = false;
    }
}

void goDes(pair<int, int> t) {
    int cy = t.first;
    int cx = t.second;
    queue<pair<int, int>> q;
    q.push({cy, cx});
    visited[cy][cx] = 1;

    while (q.size()) {
        cy = q.front().first;
        cx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N || destination[ny][nx] == -1 || visited[ny][nx])
                continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[cy][cx] + 1;
        }
    }
    for (int i = 0; i < M; i++) {
        if (deee[i].first == tp) {
            cy = deee[i].second.first;
            cx = deee[i].second.second;
        }
    }
    if (visited[cy][cx] == 0) {
        flag = false;
        return;
    }
    taxi = {cy, cx};
    destination[cy][cx] = 0;
    fuel = fuel - (visited[cy][cx] - 1);
    if (fuel < 0) {
        flag = false;
        return;
    }
    fuel += (visited[cy][cx] - 1) * 2;
}

void checkPeople() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (people[y][x] != -1 && people[y][x] != -1 && destination[y][x] != 0 && destination[y][x] != -1)
                flag = false;
        }
    }
}

void solve() {
    for (int i = 0; i < M; i++) {
        fill(&visited[0][0], &visited[0][0] + 21 * 21, 0);
        takePeople(taxi);
        fill(&visited[0][0], &visited[0][0] + 21 * 21, 0);
        goDes(taxi);
        if (!flag) {
            break;
        }
    }
    checkPeople();
    if (!flag) {
        cout << "-1" << "\n";
        return;
    }
    cout << fuel << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
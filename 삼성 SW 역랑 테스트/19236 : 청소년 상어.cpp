#include <iostream>
#include <algorithm>

using namespace std;


struct Fish {
    int y, x;
    int dir;
};

const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int ret = -1;

void go_shark(int sea[4][4], Fish fish[16], int shark_y, int shark_x, int sum) {
    //Back - tracking
    int temp_sea[4][4];
    Fish temp_fish[16];
    Fish shark;
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            temp_sea[y][x] = sea[y][x];
        }
    }
    for (int i = 0; i < 16; i++) {
        temp_fish[i] = fish[i];
    }

    // 상어 첫 등장
    int temp = temp_sea[shark_y][shark_x];
    shark.y = temp_fish[temp].y;
    shark.x = temp_fish[temp].x;
    shark.dir = temp_fish[temp].dir;
    temp_fish[temp].y = -1;
    temp_fish[temp].x = -1;
    temp_fish[temp].dir = -1;
    temp_sea[shark_y][shark_x] = -1;

    sum += temp + 1;
    ret = max(ret, sum);


    // 물고기 이동
    for (int i = 0; i < 16; i++) {
        if (temp_fish[i].y != -1) {
            int cd = temp_fish[i].dir;
            int cy = temp_fish[i].y;
            int cx = temp_fish[i].x;
            int ny = cy + dy[cd];
            int nx = cx + dx[cd];
            int j = 0;

            while (ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || (ny == shark.y && nx == shark.x)) {
                temp_fish[i].dir = (cd + (++j)) % 8;
                ny = cy + dy[temp_fish[i].dir];
                nx = cx + dx[temp_fish[i].dir];
            }

            if (temp_sea[ny][nx] != -1) {
                int change = temp_sea[ny][nx];
                temp_fish[i].y = temp_fish[change].y; // 이동하려는 물교기 좌표 바꾸기
                temp_fish[i].x = temp_fish[change].x;

                temp_sea[ny][nx] = i; // 이동된 물고기 값 바꾸기

                temp_fish[change].y = cy; // 이동된 물고기 좌표 바꾸기
                temp_fish[change].x = cx;

                temp_sea[cy][cx] = change;
            } else {
                temp_fish[i].y = ny;
                temp_fish[i].x = nx;

                temp_sea[ny][nx] = i;
                temp_sea[cy][cx] = -1;
            }

        }

    }
    //상어 이동
    for (int i = 1; i < 4; i++) {
        int sny = shark.y + dy[shark.dir] * i;
        int snx = shark.x + dx[shark.dir] * i;

        if (sny < 0 || sny >= 4 || snx < 0 || snx >= 4)
            break;
        if (temp_sea[sny][snx] != -1)
            go_shark(temp_sea, temp_fish, sny, snx, sum);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int sea[4][4];
    Fish fish[16];
    int a, b;
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            cin >> a >> b;
            a--;
            b--;
            fish[a].y = y;
            fish[a].x = x;
            fish[a].dir = b;
            sea[y][x] = a;
        }
    }

    go_shark(sea, fish, 0, 0, 0);
    cout << ret << "\n";

    return 0;
}

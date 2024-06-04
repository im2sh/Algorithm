#include <iostream>

using namespace std;

int N, ky, kx, sy, sx;
string K, S, M;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> K >> S >> N;

    kx = K[0] - 64;
    ky = K[1] - 48;
    sx = S[0] - 64;
    sy = S[1] - 48;
}

void solve() {
    while (N--) {
        cin >> M;
        int mx = 0, my = 0;
        switch (M[0]) {
            case 'R':
                mx = 1;
                if (M[1] == 'T')
                    my = 1;
                if (M[1] == 'B')
                    my = -1;
                break;
            case 'L':
                mx = -1;
                if (M[1] == 'T')
                    my = 1;
                if (M[1] == 'B')
                    my = -1;
                break;
            case 'B':
                my = -1;
                break;
            case 'T':
                my = 1;
                break;
        }

        int cur_kx = kx + mx;
        int cur_ky = ky + my;
        int cur_sx = sx + mx;
        int cur_sy = sy + my;

        if (cur_kx < 1 || cur_kx > 8 || cur_ky < 1 || cur_ky > 8)
            continue;
        if (cur_kx == sx && cur_ky == sy) {
            if (cur_sx < 1 || cur_sx > 8 || cur_sy < 1 || cur_sy > 8)
                continue;
            sx = cur_sx, sy = cur_sy;
        }
        kx = cur_kx, ky = cur_ky;
    }
    cout << (char) (kx + 64) << ky << '\n';
    cout << (char) (sx + 64) << sy;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

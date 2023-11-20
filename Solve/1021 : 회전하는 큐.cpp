#include <iostream>
#include <deque>

using namespace std;
deque<int> q;
int N, M;
int l = 0;
int r = 0;
int ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        q.push_back(i);
    }
}

void solve() {
    while (M--) {
        int num;
        cin >> num;

        for (int i = 0; i < q.size(); i++) {
            if (q[i] == num) {
                l = i;
                r = q.size() - i;
                break;
            }
        }

        if (l <= r) {
            while (1) {
                if (q.front() == num)
                    break;

                q.push_back(q.front());
                q.pop_front();
                ret++;

            }
            q.pop_front();
        } else {
            ret++;
            while (1) {
                if (q.back() == num)
                    break;

                q.push_front(q.back());
                q.pop_back();
                ret++;

            }
            q.pop_back();
        }

    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
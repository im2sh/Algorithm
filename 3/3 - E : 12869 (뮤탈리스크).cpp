#include <iostream>
#include <vector>

using namespace std;

int N;
int cnt = 0;
vector<int> scv;

bool comp(int a, int b) {
    return a > b;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int temp;
    cin >> N;
    scv.push_back(0);
    scv.push_back(0);
    scv.push_back(0);
    for (int i = 0; i < N; i++) {
        cin >> temp;
        scv[i] = temp;
    }

    while (true) {
        int check = 0;
        for (int i = 0; i < N; i++) {
            if (scv[i] <= 0) {
                check++;
            }
        }
        if (check == N) {
            break;
        }
        if (scv.size() == 3) {
            scv[0] = scv[0] - 9;
            scv[1] = scv[1] - 3;
            scv[2] = scv[2] - 1;
        } else if (scv.size() == 2) {
            scv[0] = scv[0] - 9;
            scv[1] = scv[1] - 3;
        } else
            scv[0] = scv[0] - 9;

        sort(scv.begin(), scv.end(), comp);
        cnt++;
    }
    cout << cnt << "\n";
}

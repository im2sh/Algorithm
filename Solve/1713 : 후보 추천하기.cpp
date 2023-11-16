#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, student;
vector<pair<int, int>> picture;
bool flag;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    cin >> K;
}

void delete_picture() {
    int min_count = 987654321;

    for (int i = 0; i < picture.size(); i++) {
        min_count = min(min_count, picture[i].second);
    }

    for (int i = 0; i < picture.size(); i++) {
        if (min_count == picture[i].second) {
            picture.erase(picture.begin() + i);
            break;
        }

    }
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

void solve() {
    for (int i = 0; i < K; i++) {
        cin >> student;
        flag = false;
        for (int i = 0; i < picture.size(); i++) {
            if (student == picture[i].first) {
                flag = true;
                picture[i].second++;
                break;
            }
        }

        if (flag == false) {
            if (picture.size() < N) {
                picture.push_back({student, 1});
            } else if (picture.size() == N) {
                delete_picture();
                picture.push_back({student, 1});

            }
        }
    }

    sort(picture.begin(), picture.end(), cmp);

    for (int i = 0; i < picture.size(); i++) {
        cout << picture[i].first << " ";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}



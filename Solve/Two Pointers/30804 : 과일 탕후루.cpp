#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N, ret = 1;
vector<int> fruits;
map<int, int> dict;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        fruits.push_back(temp);
    }
}

void solve() {
    int left = 0;
    int right = 1;
    dict[fruits[0]] = 1;
    int len = 1;
    while (left <= right) {
        if (right == N)
            break;
        dict[fruits[right]]++;

        if (dict.size() <= 2) {
            len++;
            right++;
            ret = max(ret, len);
        } else {
            dict[fruits[left]]--;
            if (dict[fruits[left]] == 0)
                dict.erase(fruits[left]);
            left++;
            right++;
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
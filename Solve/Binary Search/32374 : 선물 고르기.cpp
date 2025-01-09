#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> giftSize;
vector<int> boxSize;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool cmp(int a, int b) {
    return a > b;
}

void Init() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        giftSize.push_back(temp);
    }

    vector<int> tempArr;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        tempArr.push_back(temp);
    }
    map<int, int> dict;
    for (int i = 0; i < K; i++) {
        int temp;
        cin >> temp;
        dict[temp]++;
    }

    for (int i = 0; i < N; i++) {
        if (!dict[tempArr[i]]) {
            boxSize.push_back(tempArr[i]);
            continue;
        }
        dict[tempArr[i]]--;
    }

    sort(giftSize.begin(), giftSize.end(), cmp);
    sort(boxSize.begin(), boxSize.end());
}

bool go(int box) {
    int low = 0;
    int high = boxSize.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (box > boxSize[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
            return true;
        }
    }
    return false;
}

void solve() {
    for (int i = 0; i < N; i++) {
        if (go(giftSize[i])) {
            cout << giftSize[i];
            break;
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
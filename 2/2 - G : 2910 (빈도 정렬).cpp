#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define MAX_SIZE 1001

using namespace std;
map<int, int> pri, cnt;
vector<pair<int, int>> result;
int arr[MAX_SIZE];
int N, C;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return pri[a.first] < pri[b.first];
    return a.second > b.second;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
        if (!pri[arr[i]])
            pri[arr[i]] = i + 1;
    }

    for (auto it: cnt) {
        result.push_back({it.first, it.second});
    }

    sort(result.begin(), result.end(), cmp);
    for (auto i: result) {
        for (int j = 0; j < i.second; j++) {
            cout << i.first << " ";
        }
    }
    return 0;
}


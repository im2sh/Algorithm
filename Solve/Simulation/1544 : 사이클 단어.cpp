#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, ret;
vector<string> arr;
map<string, bool> MP;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        arr.push_back(temp);
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        if (MP[arr[i]])
            continue;
        for (int j = 0; j < arr[i].size(); j++) {
            string temp = "";
            for (int k = j; k < arr[i].size(); k++) {
                temp += arr[i][k];
            }
            for (int k = 0; k < j; k++) {
                temp += arr[i][k];
            }
            MP[temp] = true;
        }
        ret++;
    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

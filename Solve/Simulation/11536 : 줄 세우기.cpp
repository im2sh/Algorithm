#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<string> arr;
vector<string> A;
vector<string> B;

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
    for (int i = 0; i < N; i++) {
        A.push_back(arr[i]);
        B.push_back(arr[i]);
    }
}

bool cmp(string s1, string s2) {
    return s1 > s2;
}

void solve() {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), cmp);

    if (arr == A) {
        cout << "INCREASING";
    } else if (arr == B) {
        cout << "DECREASING";
    } else {
        cout << "NEITHER";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
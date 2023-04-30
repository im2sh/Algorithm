#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int T;

vector<int> arr;
long long ret = 0;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> T;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
}

int solve() {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            if (arr[i] + arr[j] + arr[j + 1] <= T)
                ret++;
        }
    }
    return ret;
}


int main(void) {
    FastIO();
    Init();
    cout << solve() << "\n";
    return 0;
}



//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N;
//int T;
//vector<int> arr;
//int check[10004];
//long long ret = 0;
//
//void FastIO() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//}
//
//void Init() {
//    int temp;
//    cin >> T;
//    cin >> N;
//    for (int i = 0; i < N; i++) {
//        cin >> temp;
//        arr.push_back(temp);
//    }
//    sort(arr.begin(), arr.end());
//}
//
//void solve(int depth, int idx, vector<int> v) {
//    if (depth == 3) {
//        long long tot = 0;
//        for (long long num: v)
//            tot += num;
//        if (tot <= T)
//            ret++;
//        return;
//    }
//
//    for (int i = idx; i < N; i++) {
//        v.push_back(arr[i]);
//        solve(depth + 1, i + 1, v);
//        v.pop_back();
//    }
//}
//
//
//int main(void) {
//    FastIO();
//    Init();
//    vector<int> v;
//    solve(0, 0, v);
//    cout << ret << "\n";
//    return 0;
//}
////
//// Created by 이석환 on 2023/04/28.
////

#include <iostream>
#include <vector>
#include <map>

using namespace std;
int N;
string s;
map<int, int> cnt;
vector<int> query;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> s;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        query.push_back(temp);
    }
}

void solve() {
    int last = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i != 0 && s[i] == s[i - 1]) {
            last += s[i] - 'a' + 1;
            cnt[last] = 1;
        } else {
            last = s[i] - 'a' + 1;
            cnt[last] = 1;
        }
    }

    for (int i = 0; i < query.size(); i++) {
        if (cnt[query[i]])
            cout << "Yes" << "\n";
        else
            cout << "No" << "\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}


//#include <iostream>
//#include <map>
//
//using namespace std;
//string s;
//unordered_map<char, int> cnt;
//vector<int> query;
//vector<int> result;
//int N;
//
//void FastIO() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//}
//
//void Init() {
//    int temp;
//    cin >> s;
//    cin >> N;
//    for (int i = 0; i < N; i++) {
//        cin >> temp;
//        query.push_back(temp);
//    }
//    for (int i = 0; i < s.size(); i++) {
//        cnt[s[i]]++;
//    }
//}
//
//void calcu(char num, int x) {
//    int temp = 0;
//    temp = num - 'a' + 1;
//    for (int i = 0; i < x; i++) {
//        result.push_back(temp);
//        temp += num - 'a' + 1;
//    }
//}
//
//void solve() {
//    for (auto &it: cnt) {
//        calcu(it.first, it.second);
//    }
//
//    bool flag = false;
//    for (int i = 0; i < query.size(); i++) {
//        flag = false;
//        for (int j = 0; j < result.size(); j++) {
//            if (query[i] == result[j]) {
//                flag = true;
//                break;
//            }
//        }
//        if (flag)
//            cout << "YES" << "\n";
//        else
//            cout << "NO" << "\n";
//    }
//}
//
//int main(void) {
//    FastIO();
//    Init();
//    solve();
//    return 0;
//}
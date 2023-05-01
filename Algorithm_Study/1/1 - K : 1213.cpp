#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<char, int> sen_cnt;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cnt = 0;
    string s;
    string result;
    int mid = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        sen_cnt[s[i]]++;
    }

    for (auto it: sen_cnt) {
        if ((it.second) % 2 == 1)
            cnt++;
    }

    if (cnt >= 2 && cnt != 0) {
        cout << "I'm Sorry Hansoo" << "\n";
        return 0;
    } else {
        for (int i = 'Z'; i >= 'A'; i--) {
            if (sen_cnt[i] % 2 == 1 && sen_cnt[i] != 0) {
                mid = char(i);
                sen_cnt[i]--;
            }
            for (int j = 0; j < sen_cnt[i]; j += 2) {
                result = char(i) + result;
                result += char(i);
            }
        }
    }
    if (mid)
        result.insert(result.begin() + result.size() / 2, mid);
    cout << result << "\n";

    return 0;
}
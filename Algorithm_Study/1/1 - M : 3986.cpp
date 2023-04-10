#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string s;
    char a;
    int cnt = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        vector<char> stack;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (stack.size() && stack.back() == s[j]) {
                stack.pop_back();
            } else {
                stack.push_back(s[j]);
            }
        }
        if (stack.empty())
            cnt++;
    }
    cout << cnt << "\n";
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string s;
vector<char> tempnum;
vector<string> result;
string temp;

string findnum(int a) {
    temp = "";
    bool flag = false;
    int cnt = 0;
    for (int i = 0; i < a; i++) {
        if (tempnum.size() && tempnum.front() != '0' || flag == true) {
            temp = temp + tempnum.front();
            flag = true;
        } else {
            cnt++;
            flag = false;
        }
        tempnum.erase(tempnum.begin());
    }
    if (cnt == a)
        temp = "0";
    return temp;
}

bool cmp(string a, string b) {
    if (a.size() == b.size()) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                return a[i] < b[i];
        }
    }
    return a.size() < b.size();
}

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] < 65)
                tempnum.push_back(s[j]);
            else if (tempnum.size()) {
                temp = findnum(tempnum.size());
                result.push_back(temp);
            }
        }
        if (tempnum.size()) {
            temp = findnum(tempnum.size());
            result.push_back(temp);
        }
    }
    sort(result.begin(), result.end(), cmp);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }
    return 0;
}
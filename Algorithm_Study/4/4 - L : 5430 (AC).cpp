#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;
int T, N;
string command;
deque<int> arr;


void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> T;
}


void transQ(string s) {
    int temp = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i]))
            temp = temp * 10 + (s[i] - '0');
        else if (s[i] == ',' || s[i] == ']' && temp != 0) {
            arr.push_back(temp);
            temp = 0;
        }
    }
}


void cal() {
    int Rcnt = 0;
    bool Rcondition = true;
    int Dcnt = 0;
    for (int i = 0; i < command.length(); i++) {
        if (command[i] == 'R')
            Rcnt++;
        else
            Dcnt++;
    }

    for (int i = 0; i < command.length(); i++) {
        if (command[i] == 'R') {
            Rcondition = !Rcondition;
        } else {
            Dcnt--;
            if (arr.size() >= 1) {
                if (Rcondition)
                    arr.pop_front();
                else
                    arr.pop_back();
            } else {
                cout << "error" << "\n";
                return;
            }
        }
    }

    if (Rcnt % 2)
        reverse(arr.begin(), arr.end());

    int size = arr.size();

    if (Dcnt > 0 && arr.size() == 0) {
        cout << "error" << "\n";
        return;
    }

    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        if (i != (size - 1))
            cout << arr[i] << ",";
        else
            cout << arr[i];
    }
    cout << "]\n";
}

void solve() {
    string temp;
    while (T--) {
        cin >> command;
        cin >> N;
        cin >> temp;
        arr.clear();
        transQ(temp);
        cal();
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

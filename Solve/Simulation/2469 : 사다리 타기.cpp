#include <iostream>
#include <string>

using namespace std;

int K, N;
string result = "";
string alpha = "";
string ret = "";
string ladder[1001];
bool flag = true;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    string temp;
    char tempAlpha = 'A';
    cin >> K;
    cin >> N;
    cin >> result;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        ladder[i] = temp;
    }
    for (int i = 0; i < K; i++) {
        alpha += tempAlpha;
        tempAlpha++;
    }
}


void solve() {
    int breakline = 0;
    for (int i = 0; i < N; i++) {
        string line = ladder[i];
        string temp = "";
        if (line[0] == '?') {
            breakline = i;
            break;
        }
        for (int j = 0; j < K; j++) {
            if (line[j] == '-') {
                temp += alpha[j + 1];
                temp += alpha[j];
                j++;
            } else {
                temp += alpha[j];
            }
        }
        alpha = temp;
    }

    for (int i = N - 1; i > breakline; i--) {
        string line = ladder[i];
        string temp = "";
        for (int j = 0; j < K; j++) {
            if (line[j] == '-') {
                temp += result[j + 1];
                temp += result[j];
                j++;
            } else {
                temp += result[j];
            }
        }
        result = temp;
    }

    for (int i = 0; i < K - 1; i++) {
        if (alpha[i] == result[i]) {
            ret += '*';
        } else if (alpha[i] == result[i + 1] && alpha[i + 1] == result[i]) {
            ret += '-';
            char temp = alpha[i];
            alpha[i] = alpha[i + 1];
            alpha[i + 1] = temp;
        } else {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << ret;
    else
        for (int i = 0; i < K - 1; i++) {
            cout << 'x';
        }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
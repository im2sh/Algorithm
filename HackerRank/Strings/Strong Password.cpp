#include <iostream>
#include <string>

using namespace std;
string numbers = "0123456789";
string lower_case = "abcdefghijklmnopqrstuvwxyz";
string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string special_characters = "!@#$%^&*()-+";
int N;
string s;
int cnt;
bool check[4];
int size1;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void Init() {
    cin >> N;
    cin >> s;
}

void calcu() {
    for (int i = 0; i < 4; i++) {
        if (!check[i]) {
            cnt++;
            size1++;
        }
    }

    while (size1 < 6) {
        size1++;
        cnt++;
    }
};

int solve() {
    size1 = s.size();
    for (int i = 0; i < s.size(); i++) {

        for (int a = 0; a < numbers.size(); a++) {
            if (s[i] == numbers[a]) {
                check[0] = true;
                break;
            }
        }

        for (int b = 0; b < lower_case.size(); b++) {
            if (s[i] == lower_case[b]) {
                check[1] = true;
                break;
            }
        }


        for (int c = 0; c < upper_case.size(); c++) {
            if (s[i] == upper_case[c]) {
                check[2] = true;
                break;
            }
        }


        for (int d = 0; d < special_characters.size(); d++) {
            if (s[i] == special_characters[d]) {
                check[3] = true;
                break;
            }
        }

    }

    calcu();

    return cnt;
}


int main(void) {
    FastIO();
    Init();
    cout << solve();
    return 0;
}
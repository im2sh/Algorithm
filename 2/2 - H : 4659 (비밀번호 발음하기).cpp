#include <iostream>
#include <string>

using namespace std;

char mo[5] = {'a', 'e', 'i', 'o', 'u'};

string pw;

bool mflag;
bool flag;
bool M;

bool isM(char a) {
    for (int i = 0; i < pw.size(); i++) {
        for (int j = 0; j < 5; j++) {
            if (a == mo[j])
                return true;
        }
    }
    return false;
}

void printPw() {
    pw = '<' + pw + '>';
    if (flag == true && mflag == true)
        cout << pw + " is acceptable." << "\n";
    else
        cout << pw + " is not acceptable." << "\n";
}

int main(void) {
    pw = "";
    int mldx, vldx;
    while (true) {
        cin >> pw;
        if (pw == "end")
            break;
        mldx = 0;
        vldx = 0;
        M = false;
        flag = true;
        mflag = false;
        int prev = 0;
        for (int i = 0; i < pw.size(); i++) {
            if (isM(pw[i])) {
                mldx++;
                vldx = 0;
                mflag = true;
            } else {
                mldx = 0;
                vldx++;

            }
            if (mldx == 3 || vldx == 3) {
                flag = false;
                break;
            }
            if (i >= 1 && (prev == pw[i]) && (pw[i] != 'e' && pw[i] != 'o'))
                flag = false;
//            if (i(pw[i] == pw[i - 1]) && pw[i] != 'e' && pw[i] != 'o')
//                flag = false;
            prev = pw[i];
        }
        printPw();
    }
    return 0;
}

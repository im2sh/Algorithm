#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string find_s;
    string s;
    string left;
    string right;
    cin >> n;
    cin >> find_s;
    int pos = find_s.find('*');
    left = find_s.substr(0, pos);
    right = find_s.substr(pos + 1);

    for (int i = 0; i < n; i++) {
        cin >> s;
        if ((left.size() + right.size()) > s.size())
            cout << "NE" << "\n";
        else {
            if ((left == s.substr(0, left.size())) && (right == s.substr(s.size() - right.size())))

                cout << "DA" << "\n";
            else
                cout << "NE" << "\n";
        }
    }
}

// 문제를 이해하지 못한 CASE 본보기로 삼자 !
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    int n;
//    string find;
//    char left[50];
//    char right[50];
//    bool flag = false;
//    int left_point = 0;
//    int right_point = 0;
//    int sen_len = 0;
//    cin >> n;
//    cin >> find;
//    char s[100];
//    for (int i = 0; i < find.size(); i++) {
//        if (find[i] == '*') {
//            left_point = i;
//            break;
//        }
//        left[i] = find[i];
//    }
//
//    for (int i = left_point; i < find.size(); i++) {
//        right[i] = find[i];
//        right_point = i;
//    }
//
//    for (int i = 0; i < n; i++) {
//        scanf("%s", s);
//        sen_len = strlen(s);
//        for (int j = 0; j < left_point; j++) {
//            if (s[j] == left[j] && sen_len != 1)
//                flag = true;
//            else
//                flag = false;
//        }
//        for (int k = left_point + 1; k < right_point; k++) {
//            if (s[k] == right[k])
//                flag = true;
//            else
//                flag = false;
//        }
//        if (flag == true)
//            cout << "DA" << "\n";
//        else
//            cout << "NE" << "\n";
//    }
//
//    return 0;
//}

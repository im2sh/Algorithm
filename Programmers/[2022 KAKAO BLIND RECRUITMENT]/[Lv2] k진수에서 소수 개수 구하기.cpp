#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

string number = "";
vector<int> v;


int judge(string num) {
    ll N = stoll(num);

    if (N == 1)
        return 0;
    for (ll i = 2; i <= sqrt(N); i++) {
        if (N % i == 0)
            return 0;
    }
    return 1;
}

void transfer(int n, int k) {
    int d, r;

    while (n != 0) {
        r = n % k;
        char temp = r + '0';
        number = temp + number;
        n /= k;
    }
}

int solution(int n, int k) {
    int answer = -1;
    transfer(n, k);
    string temp = "";
    temp += number[0];
    for (int i = 1; i < number.length(); i++) {
        if (number[i] != '0') {
            temp += number[i];
        } else if (number[i] == '0') {
            if (temp.length() == 0)
                continue;
            answer += judge(temp);
            temp = "";
        }
    }

    if (temp.length() != 0) {
        answer += judge(temp);
    }
    return answer + 1;
}

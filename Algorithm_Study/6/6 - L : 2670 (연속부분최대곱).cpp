#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<double> arr;
double ret;

void FastIO() {

}

void Init() {
    double temp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        double sum = 1;
        for (int j = i; j < N; j++) {
            sum *= arr[j];
            ret = max(ret, sum);
        }
    }
    printf("%.3lf", ret + 0.00001);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
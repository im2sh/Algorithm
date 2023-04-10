#include <iostream>
#include <algorithm>

using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    int tem[100000];
    int psum[100000] = {0,};
    int result = -10000001;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> tem[i];
        psum[i] = psum[i - 1] + tem[i];
    }

    for (int i = K; i <= N; i++) {
        result = max(result, psum[i] - psum[i - K]);
    }

    cout << result << "\n";

    return 0;
}


/**
 * Stack 사용
 */

//vector<int> temperature;
//vector<int> temp_temperature;
//vector<int> result;
//
//void return_push(int n) {
//    int temp = 0;
//    for (int i = 0; i < n; i++) {
//        temp = temp_temperature.back();
//        temperature.push_back(temp);
//        temp_temperature.pop_back();
//    }
//}
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    int N, K, x;
//    int flag = 0;
//    int temp_sum = 0;
//    int temp;
//
//    cin >> N >> K;
//
//    for (int i = 0; i < N; i++) {
//        cin >> x;
//        temperature.push_back(x);
//    }
//
//    while (!temperature.empty()) {
//        temp_sum = 0;
//        flag = 0;
//        flag = K;
//        while (flag--) {
//            temp_sum += temperature.back();
//            if (flag == K - 1)
//                temperature.pop_back();
//            else {
//                temp_temperature.push_back(temperature.back());
//                temperature.pop_back();
//            }
//        }
//        return_push(K - 1);
//        result.push_back(temp_sum);
//    }
//    cout << *max_element(result.begin(), result.end());
//}
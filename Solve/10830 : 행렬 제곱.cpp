#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
ll N, B;

vector<vector<ll>> temp;

vector<vector<ll>> calcuM(vector<vector<ll>> original, vector<vector<ll>> temp) {
    vector<vector<ll>> result_temp(N, vector<ll>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result_temp[i][j] += ((original[i][k]) * (temp[k][j])) % 1000;
                result_temp[i][j] %= 1000;
            }
        }
    }
    return result_temp;
}

vector<vector<ll>> powerM(vector<vector<ll>> arr, ll B) {
    if (B == 1)
        return arr;
    if (B % 2 == 0) {
        temp = powerM(arr, B / 2);
        return calcuM(temp, temp);
    } else {
        temp = powerM(arr, B - 1);
        return calcuM(arr, temp);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> B;
    vector<vector<ll>> arr(N, vector<ll>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<ll>> result = powerM(arr, B);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] % 1000 << " ";
        }
        cout << "\n";
    }
    return 0;
}

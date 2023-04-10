#include <iostream>
#include <map>
#include <stack>

#define SIZE 1000004
using namespace std;
int N;
int x;
int arr[SIZE];
stack<int> temp;
int result[SIZE];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        result[i] = -1;
    }
    for (int i = 0; i < N; i++) {
        while (!temp.empty() && arr[temp.top()] < arr[i]) {
            result[temp.top()] = arr[i];
            temp.pop();
        }
        temp.push(i);
    }
    for (int i = 0; i < N; i++)
        cout << result[i] << "\n";

    return 0;
}
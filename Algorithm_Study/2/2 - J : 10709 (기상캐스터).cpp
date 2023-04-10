#include <iostream>

using namespace std;
#define SIZE 101

int H, W;
string weather;
int temp;
int arr[SIZE][SIZE];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> H >> W;
    fill(&arr[0][0], &arr[0][0] + SIZE * SIZE, -1);
    for (int i = 1; i <= H; i++) {
        cin >> weather;
        weather = " " + weather;
        for (int j = 1; j <= W; j++) {
            if (weather[j] == 'c') {
                temp = 0;
                arr[i][j] = temp++;
            } else if (weather[j] == '.' && arr[i][j - 1] == -1)
                continue;
            else
                arr[i][j] = temp++;
        }
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
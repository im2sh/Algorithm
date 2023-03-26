#include <iostream>

#pragma warning (disable:4996)

#include <string>
#include <algorithm>

using namespace std;

int N;
int team;
int Ateam, Bteam;
string goal;
int Atime;
int Btime;
int prevT;
int m, s;

int transtime(int i, int j) {
    return stoi(goal.substr(i, j));
}

int main(void) {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        cin >> team;
        cin >> goal;
        m = transtime(0, 2);
        s = transtime(3, 2);

        if (Ateam > Bteam)
            Atime = Atime + (m * 60) + s - prevT;
        else if (Bteam > Ateam)
            Btime = Btime + (m * 60) + s - prevT;

        if (team == 1) {
            Ateam += 1;
        } else {
            Bteam += 1;
        }

        prevT = (60 * m) + s;
    }
    if (Ateam > Bteam) {
        Atime = Atime + (60 * 48) - prevT;
    } else if (Bteam > Ateam) {
        Btime = Btime + (60 * 48) - prevT;
    }
    printf("%02d:%02d\n", Atime / 60, Atime % 60);
    printf("%02d:%02d\n", Btime / 60, Btime % 60);
    return 0;
}
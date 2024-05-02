#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

typedef struct info {
    int dest, weight;
} Info;

struct cmp {
    bool operator()(Info a, Info b) {
        return a.weight > b.weight;
    }
};

int TC;
int N, M, T, S, G, H;
vector<Info> graph[2004];
vector<int> dest;
int sDist[2004];
int gDist[2004];
int hDist[2004];
vector<int> ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void go(int start, int dist[2004]) {
    priority_queue<Info, vector<Info>, cmp> pq;
    pq.push({start, 0});
    dist[start] = 0;

    while (pq.size()) {
        int cur = pq.top().dest;
        int weight = pq.top().weight;
        pq.pop();

        if (dist[cur] < weight)
            continue;

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].dest;
            int next_weight = graph[cur][i].weight;

            if (dist[next] > weight + next_weight) {
                dist[next] = weight + next_weight;
                pq.push({next, weight + next_weight});
            }
        }
    }
}

void graphInit() {
    for (int i = 0; i < 2004; i++) {
        graph[i].clear();
    }
    dest.clear();
    ret.clear();
    fill(&sDist[0], &sDist[0] + 2004, INT_MAX);
    fill(&gDist[0], &gDist[0] + 2004, INT_MAX);
    fill(&hDist[0], &hDist[0] + 2004, INT_MAX);
    cin >> N >> M >> T;
    cin >> S >> G >> H;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    for (int i = 0; i < T; i++) {
        int temp;
        cin >> temp;
        dest.push_back(temp);
    }
}

void findPath() {
    for (int i = 0; i < dest.size(); i++) {
        if (sDist[dest[i]] == sDist[G] + gDist[H] + hDist[dest[i]])
            ret.push_back(dest[i]);
        else if (sDist[dest[i]] == sDist[H] + hDist[G] + gDist[dest[i]])
            ret.push_back(dest[i]);
    }
}

void solve() {
    while (TC--) {
        graphInit();
        go(S, sDist);
        go(G, gDist);
        go(H, hDist);
        findPath();

        sort(ret.begin(), ret.end());
        for (int i = 0; i < ret.size(); i++) {
            cout << ret[i] << ' ';
        }
        cout << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

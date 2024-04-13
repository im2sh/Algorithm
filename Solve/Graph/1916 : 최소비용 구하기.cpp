/**
 * 1. 우선순위 큐 구조체 사용할 때, 사용 방법이 다름
 * 2. 초기에 시작점에 간선이 많은 경우가 있다. 그렇기 때문에 pq.push({시작 정점,0}); 해야 함 -> 간선의 가중치가 큰 경우 갱신을 위해서 계속해서 돌기 때문
 * 3. 현재 해당 정점에 저장되어 있는 거리보다 pq에 담겨져 온 거리가 더 멀다면 continue로 무시
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct node {
    int e;
    int w;
} Node;

int N, M;
vector<Node> graph[1001];
int dist[1001];
int S, E;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a - 1].push_back({b - 1, c});
    }
    cin >> S >> E;
    S -= 1;
    E -= 1;
    for (int i = 0; i < N; i++) {
        dist[i] = 987654321;
    }
}

struct cmp {
    bool operator()(Node a, Node b) {
        return a.w > b.w;
    }
};

void solve() {
    priority_queue<Node, vector<Node>, cmp> pq;
    pq.push({S, 0});

    while (pq.size()) {
        int cur = pq.top().e;
        int weight = pq.top().w;
        pq.pop();

        if (dist[cur] < weight)
            continue;

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].e;
            int next_weight = graph[cur][i].w;

            if (dist[next] > weight + next_weight) {
                pq.push({next, weight + next_weight});
                dist[next] = weight + next_weight;
            }
        }
    }
    cout << dist[E];
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

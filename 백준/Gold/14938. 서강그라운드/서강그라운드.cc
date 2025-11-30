#include <iostream>
#include <vector>
#include <queue>

using std::greater;
using std::pair;
using std::priority_queue;
using std::vector;

vector<uint16_t> dijkstra(uint16_t start, const vector<vector<pair<uint16_t, uint16_t>>> &graph)
{
    uint16_t n = graph.size();
    vector<uint16_t> dist(n, UINT16_MAX);
    priority_queue<pair<uint16_t, uint16_t>, vector<pair<uint16_t, uint16_t>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [cur_dist, cur_node] = pq.top();
        pq.pop();

        // 이미 더 짧은 경로로 방문했었다면
        if (cur_dist > dist[cur_node])
            continue;

        // 인접 노드들 확인
        for (auto [next_node, weight] : graph[cur_node])
        {
            uint16_t new_dist = cur_dist + weight;
            if (new_dist < dist[next_node])
            {
                pq.push({new_dist, next_node});
                dist[next_node] = new_dist;
            }
        }
    }

    return dist;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n; // n: [1, 100] 지역의 개수
    uint16_t m; // m: [1, 15] 수색 범위
    uint16_t r; // r: [1, 100] 길의 개수
    std::cin >> n >> m >> r;

    // [1, 30] 각 구역에 있는 아이템의 수
    vector<uint16_t> items(n);

    for (uint16_t i = 0; i < n; i++)
    {
        std::cin >> items[i];
    }

    // 인접 리스트: { 연결된 노드, 거리 }
    vector<vector<pair<uint16_t, uint16_t>>> graph(n);

    for (uint16_t i = 0; i < r; i++)
    {
        uint16_t a; // [1, 100] 지역 번호
        uint16_t b; // [1, 100] 지역 번호
        uint16_t l; // [1, 15] a랑 b를 연결하는 길의 길이
        std::cin >> a >> b >> l;
        graph[a - 1].push_back({b - 1, l});
        graph[b - 1].push_back({a - 1, l});
    }

    /**
     * 모든 노드 쌍 간의 최단 거리 구하기
     *
     * 다익스트라를 n번 실행
     * O(n * (V + E) * log V)
     */

    uint16_t maxItems = 0;

    for (uint16_t i = 0; i < n; i++)
    {
        vector<uint16_t> dist = dijkstra(i, graph);

        uint16_t sum = 0;
        for (uint16_t j = 0; j < n; j++)
        {
            if (dist[j] <= m)
            {
                sum += items[j];
            }
        }
        maxItems = std::max(maxItems, sum);
    }

    std::cout << maxItems << '\n';

    return 0;
}
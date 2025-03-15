/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1504                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1504                           #+#        #+#      #+#    */
/*   Solved: 2025/03/06 16:10:51 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>

using std::greater;
using std::pair;
using std::priority_queue;
using std::vector;

using p_ui_us = pair<uint32_t, uint16_t>;

typedef struct Edge
{
    uint16_t to;
    uint16_t weight;
    Edge(uint16_t t, uint16_t w) : to(t), weight(w) {}
} edge;

vector<uint32_t> dijkstra(const uint16_t &start, const vector<vector<edge>> &graph)
{
    const uint32_t LIMIT = UINT32_MAX;
    int n = graph.size();
    vector<uint32_t> dist(n, LIMIT);
    priority_queue<p_ui_us, vector<p_ui_us>, greater<p_ui_us>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [cur_dist, cur] = pq.top();
        pq.pop();
        if (cur_dist > dist[cur])
            continue;
        for (const auto &e : graph[cur])
        {
            uint16_t next = e.to;
            uint32_t n_dist = cur_dist + e.weight;
            if (n_dist < dist[next])
            {
                dist[next] = n_dist;
                pq.push({n_dist, next});
            }
        }
    }
    return dist;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n; // 정점의 개수, 2 <= n <= 800
    uint32_t e; // 간선의 개수, 0 <= e <= 200,000
    std::cin >> n >> e;

    vector<vector<edge>> adj_list(n);
    for (uint32_t i = 0; i < e; i++)
    {
        uint16_t a, b, c;
        std::cin >> a >> b >> c;
        a--;
        b--;
        adj_list[a].push_back(Edge(b, c));
        adj_list[b].push_back(Edge(a, c));
    }

    uint16_t v_1, v_2;
    std::cin >> v_1 >> v_2;
    v_1--;
    v_2--;

    // 1번(인덱스 0), v_1, v2에서 각각 다익스트라 실행
    const uint32_t LIMIT = UINT32_MAX;
    vector<uint32_t> dist_1 = dijkstra(0, adj_list);
    vector<uint32_t> dist_v1 = dijkstra(v_1, adj_list);
    vector<uint32_t> dist_v2 = dijkstra(v_2, adj_list);

    // 후보 경로 1: 1 -> v_1 -> v_2 -> N (인덱스 n-1)
    uint32_t candidate_1 = LIMIT;
    if (dist_1[v_1] != LIMIT && dist_v1[v_2] != LIMIT && dist_v2[n - 1] != LIMIT)
        candidate_1 = dist_1[v_1] + dist_v1[v_2] + dist_v2[n - 1];

    // 후보 경로 2: 1 -> v_2 -> v_1 -> N (인덱스 n-1)
    uint32_t candidate_2 = LIMIT;
    if (dist_1[v_2] != LIMIT && dist_v2[v_1] != LIMIT && dist_v1[n - 1] != LIMIT)
        candidate_2 = dist_1[v_2] + dist_v2[v_1] + dist_v1[n - 1];

    uint32_t ans = std::min(candidate_1, candidate_2);
    if (ans == LIMIT)
        std::cout << -1 << "\n";
    else
        std::cout << ans << "\n";

    return 0;
}

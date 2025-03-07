/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1238                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1238                           #+#        #+#      #+#    */
/*   Solved: 2025/03/06 16:10:57 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>

using std::greater;
using std::priority_queue;
using std::vector;

typedef struct Edge
{
    uint16_t to;
    uint16_t weight;
    Edge(uint16_t a, uint16_t b) : to(a), weight(b) {}
} edge;

typedef struct Node
{
    uint32_t dist;
    uint16_t vertex;
    Node(uint32_t a, uint16_t b) : dist(a), vertex(b) {}
} node;

bool operator>(const Node &a, const Node &b)
{
    return a.dist > b.dist;
}

void dijkstra(const uint16_t &start, const vector<vector<edge>> &graph, vector<uint32_t> &dist)
{
    uint16_t n = graph.size();
    dist.assign(n, UINT32_MAX);
    priority_queue<node, vector<node>, greater<node>> pq;
    dist[start] = 0;
    pq.push({start, 0});

    while (!pq.empty())
    {
        auto [cur, cur_dist] = pq.top();
        pq.pop();
        if (cur_dist > dist[cur])
            continue;
        for (const auto &[to, weight] : graph[cur])
        {
            if (dist[to] > cur_dist + weight)
            {
                dist[to] = cur_dist + weight;
                pq.push({to, dist[to]});
            }
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n; // 1 <= n <= 1,000
    uint16_t m; // 1 <= m <= 10,000
    uint16_t x; // 1 <= x <= n

    std::cin >> n >> m >> x;
    x--;

    vector<vector<edge>> graph(n), reverse_graph(n);
    for (uint16_t i = 0; i < m; i++)
    {
        uint16_t u, v, t;
        std::cin >> u >> v >> t;
        u--;
        v--;
        graph[u].push_back({v, t});
        reverse_graph[v].push_back({u, t});
    }

    vector<uint32_t> dist_from_x;
    dijkstra(x, graph, dist_from_x);

    vector<uint32_t> dist_to_x;
    dijkstra(x, reverse_graph, dist_to_x);

    uint32_t answer = 0;
    for (int i = 0; i < n; i++)
    {
        answer = std::max(answer, dist_from_x[i] + dist_to_x[i]);
    }

    std::cout << answer << "\n";
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1753                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1753                           #+#        #+#      #+#    */
/*   Solved: 2025/03/15 18:32:25 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>

using std::greater;
using std::priority_queue;
using std::vector;

struct edge
{
    uint16_t to;
    uint16_t weight;
    edge(uint16_t a, uint16_t b) : to(a), weight(b) {}
};

struct node
{
    uint16_t num;
    uint32_t min_dist;
    node(uint16_t a, uint32_t b) : num(a), min_dist(b) {}
};

bool operator>(const node &n1, const node &n2)
{
    return n1.min_dist > n2.min_dist;
}

vector<uint32_t> dijkstra(const uint16_t &start, const vector<vector<edge>> &graph)
{
    uint16_t n = graph.size();
    vector<uint32_t> dist(n, UINT32_MAX);
    priority_queue<node, vector<node>, greater<node>> pq;

    dist[start] = 0;
    pq.push({start, 0});

    while (!pq.empty())
    {
        auto [cur, cur_dist] = pq.top();
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
                pq.push({next, n_dist});
            }
        }
    }

    return dist;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t vertex; // 1 <= v <= 20,000
    uint32_t e;      // 1 <= e <= 300,000
    uint16_t start;  // 시작 노드 번호

    std::cin >> vertex >> e >> start;
    start--;

    vector<vector<edge>> adj_list(vertex);

    for (uint32_t i = 0; i < e; i++)
    {
        uint16_t u, v, w;
        std::cin >> u >> v >> w;
        adj_list[u - 1].push_back({v - 1, w});
    }
    vector<uint32_t> result = dijkstra(start, adj_list);
    for (auto i = result.begin(); i != result.end(); i++)
    {
        if (*i != UINT32_MAX)
        {
            std::cout << *i << '\n';
        }
        else
        {
            std::cout << "INF" << '\n';
        }
    }
    return 0;
}
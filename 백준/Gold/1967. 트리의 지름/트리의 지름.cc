/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1967                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1967                           #+#        #+#      #+#    */
/*   Solved: 2025/03/25 14:48:54 by skgudwls      ###          ###   ##.kr    */
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
    uint32_t weight;
    edge(uint16_t a, uint32_t b) : to(a), weight(b) {}
};

struct farthest
{
    uint16_t num;
    uint32_t dist;
    farthest(uint16_t a, uint32_t b) : num(a), dist(b) {}
};

struct node
{
    uint16_t cur;
    uint32_t cur_dist;
    node(uint16_t a, uint32_t b) : cur(a), cur_dist(b) {}
};

bool operator>(const node &n1, const node &n2)
{
    return n1.cur_dist > n2.cur_dist;
}

farthest dijkstra(const vector<vector<edge>> &tree, uint16_t start)
{
    uint16_t n = tree.size();

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
        for (const auto &[to, weight] : tree[cur])
        {
            if (cur_dist + weight >= dist[to])
                continue;
            pq.push({to, cur_dist + weight});
            dist[to] = cur_dist + weight;
        }
    }

    uint32_t max = 0;
    uint16_t num = 0;
    for (uint16_t i = 0; i < n; i++)
    {
        if (dist[i] > max)
        {
            max = dist[i];
            num = i;
        }
    }

    return {num, max};
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n; // 1 <= n <= 10,000
    std::cin >> n;
    vector<vector<edge>> adj_list(n);
    for (uint16_t i = 0; i < n - 1; i++)
    {
        uint16_t from, to;
        uint32_t weight;
        std::cin >> from >> to >> weight;
        from--;
        to--;
        // 양방향 그래프
        adj_list[from].push_back({to, weight});
        adj_list[to].push_back({from, weight});
    }

    // 임의의 노드에서 다익스트라 실행
    auto [one_of_farthest_node, _] = dijkstra(adj_list, 0);
    // 가장 먼 두 노드 중 하나를 반환받고 이를 시작점으로 다시 실행
    auto [__, result] = dijkstra(adj_list, one_of_farthest_node);

    std::cout << result << '\n';

    return 0;
}
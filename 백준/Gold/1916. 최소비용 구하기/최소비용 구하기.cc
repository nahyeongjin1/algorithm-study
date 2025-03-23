/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1916                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1916                           #+#        #+#      #+#    */
/*   Solved: 2025/03/23 14:04:56 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>

using std::greater;
using std::priority_queue;
using std::vector;

struct route
{
    uint16_t to;
    uint32_t weight;
    route(uint16_t a, uint32_t b) : to(a), weight(b) {}
};

struct city
{
    uint16_t num;
    uint64_t price; // maximum 10,000,000,000
    city(uint16_t a, uint64_t b) : num(a), price(b) {}
};

bool operator>(const city &c1, const city &c2)
{
    return c1.price > c2.price;
}

uint64_t dijkstra(const vector<vector<route>> &graph, uint16_t start, uint16_t end)
{
    start--;
    end--;
    uint16_t n = graph.size();
    vector<uint64_t> result(n, UINT64_MAX);
    priority_queue<city, vector<city>, greater<city>> pq;

    result[start] = 0;
    pq.push({start, 0});

    while (!pq.empty())
    {
        auto [cur, cur_price] = pq.top();
        pq.pop();
        if (result[cur] < cur_price)
            continue;
        for (const route &r : graph[cur])
        {
            auto [to, weight] = r;
            if (result[to] <= cur_price + weight)
                continue;
            pq.push({to, cur_price + weight});
            result[to] = cur_price + weight;
        }
    }

    return result[end];
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n; // 1 <= n <= 1,000
    uint32_t m; // 1 <= m <= 100,000

    std::cin >> n >> m;
    vector<vector<route>> adj_list(n);
    for (uint32_t i = 0; i < m; i++)
    {
        uint16_t from, to;
        uint32_t price;
        std::cin >> from >> to >> price;
        adj_list[from - 1].push_back({to - 1, price});
    }
    uint16_t start, end;
    std::cin >> start >> end;

    std::cout << dijkstra(adj_list, start, end) << '\n';

    return 0;
}
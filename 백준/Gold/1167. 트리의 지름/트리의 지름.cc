/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1167                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1167                           #+#        #+#      #+#    */
/*   Solved: 2025/03/04 08:49:48 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <stack>

using std::pair;
using std::stack;
using std::vector;

typedef struct Edge
{
    uint32_t to;
    uint32_t weight;
    Edge(uint32_t a, uint32_t b) : to(a), weight(b) {}
} edge;

pair<uint32_t, uint32_t> dfs(const uint32_t &start, const vector<vector<edge>> &adj_list)
{
    uint32_t farthest = start;
    uint32_t max_dist = 0;
    vector<bool> visited(adj_list.size(), false);
    stack<pair<uint32_t, uint32_t>> st;

    // {현재 위치, 거리합}
    st.push({start, 0});
    visited[start] = true;

    while (!st.empty())
    {
        auto [cur, dist] = st.top();
        st.pop();
        if (dist > max_dist)
        {
            max_dist = dist;
            farthest = cur;
        }
        for (const auto &[to, weight] : adj_list[cur])
        {
            if (!visited[to])
            {
                visited[to] = true;
                st.push({to, dist + weight});
            }
        }
    }
    return {farthest, max_dist};
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint32_t v; // 2 <= v <= 100,000
    std::cin >> v;

    vector<vector<edge>> adj_list(v);
    for (uint32_t i = 0; i < v; i++)
    {
        uint32_t num;
        std::cin >> num;
        while (true)
        {
            int32_t node;
            std::cin >> node;
            if (node == -1)
                break;
            uint32_t weight;
            std::cin >> weight;
            adj_list[num - 1].push_back({node - 1, weight});
        }
    }

    // 임의의 한 점에서 가장 멀리 있는 정점 탐색
    auto [farthest, _] = dfs(0, adj_list);
    // 가장 멀었던 정점에서 다시 가장 먼 정점 탐색
    auto [__, diameter] = dfs(farthest, adj_list);

    std::cout << diameter << '\n';

    return 0;
}
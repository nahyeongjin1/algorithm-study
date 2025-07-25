/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11779                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11779                          #+#        #+#      #+#    */
/*   Solved: 2025/07/25 18:11:13 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using std::greater;
using std::pair;
using std::priority_queue;
using std::stack;
using std::vector;

// {to, cost}
using edge = pair<uint16_t, uint32_t>;
// {total, num}
using node = pair<uint64_t, uint16_t>;

bool operator>(node n1, node n2)
{
    return n1.first > n2.first;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n;
    uint32_t m;

    std::cin >> n >> m;

    vector<vector<edge>> graph(n + 1, vector<edge>());
    for (uint32_t i = 0; i < m; i++)
    {
        uint16_t from, to;
        uint32_t cost;
        std::cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
    }

    uint16_t start, end;
    std::cin >> start >> end;

    vector<uint64_t> dist(n + 1, UINT64_MAX);
    dist[start] = 0;
    vector<uint16_t> prev_node(n + 1, 0);
    priority_queue<node, vector<node>, greater<node>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [now_total, now_num] = pq.top();
        pq.pop();

        if (dist[now_num] < now_total)
            continue;

        for (const auto &[next_to, next_cost] : graph[now_num])
        {
            if (dist[next_to] > now_total + next_cost)
            {
                dist[next_to] = now_total + next_cost;
                prev_node[next_to] = now_num;
                pq.push({dist[next_to], next_to});
            }
        }
    }

    stack<uint16_t> st;
    st.push(end);

    while (st.top() != start)
    {
        uint16_t now = st.top();
        st.push(prev_node[now]);
    }

    std::cout << dist[end] << '\n'
              << st.size() << '\n';
    while (!st.empty())
    {
        std::cout << st.top();
        st.pop();
        if (!st.empty())
            std::cout << ' ';
    }

    return 0;
}
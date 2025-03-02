/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 16928                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/16928                          #+#        #+#      #+#    */
/*   Solved: 2025/03/02 15:45:52 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using std::map;
using std::pair;
using std::queue;
using std::vector;

typedef struct Node
{
    uint16_t cur;
    uint16_t count;
    Node(uint16_t cur, uint16_t count) : cur(cur), count(count) {}
} node;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    constexpr u_short LIMIT = 100;
    uint16_t n, m; // 1 <= n, m <= 15
    std::cin >> n >> m;

    map<uint16_t, uint16_t> teleport;
    for (uint16_t i = 0; i < n + m; i++)
    {
        uint16_t u, v;
        std::cin >> u >> v;
        teleport.insert({u - 1, v - 1});
    }

    vector<bool> visited(LIMIT, false);
    queue<node> q;

    q.push({0, 0});
    visited[0] = true;

    while (!q.empty())
    {
        auto [cur, count] = q.front();
        if (cur >= LIMIT - 1)
        {
            std::cout << count << '\n';
            break;
        }
        q.pop();
        uint16_t i;
        for (i = 1; i <= 6; i++)
        {
            uint16_t next = cur + i;
            if (next > LIMIT - 1)
            {
                continue;
            }
            auto search = teleport.find(next);
            if (search != teleport.end())
            {
                next = search->second;
            }
            if (visited[next])
            {
                continue;
            }
            q.push({next, count + 1});
            visited[next] = true;
        }
    }

    return 0;
}
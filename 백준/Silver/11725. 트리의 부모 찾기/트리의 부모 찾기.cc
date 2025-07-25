/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11725                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11725                          #+#        #+#      #+#    */
/*   Solved: 2025/07/24 15:10:13 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>

using std::queue;
using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint32_t n;
    std::cin >> n;

    vector<vector<uint32_t>> tree(n + 1, vector<uint32_t>());

    for (uint32_t i = 0; i < n - 1; i++)
    {
        uint32_t a, b;
        std::cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<uint32_t> parent(n + 1, 0);
    queue<uint32_t> q;
    q.push(1);

    while (!q.empty())
    {
        uint32_t now = q.front();
        q.pop();

        for (const uint32_t &node : tree[now])
        {
            if (!parent[node])
            {
                parent[node] = now;
                q.push(node);
            }
        }
    }

    for (uint32_t i = 2; i <= n; i++)
    {
        std::cout << parent[i] << '\n';
    }

    return 0;
}
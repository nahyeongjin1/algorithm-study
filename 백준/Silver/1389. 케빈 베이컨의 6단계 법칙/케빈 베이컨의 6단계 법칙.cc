/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1389                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1389                           #+#        #+#      #+#    */
/*   Solved: 2025/02/23 22:09:36 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <queue>

using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned short n, m;
    std::cin >> n >> m;

    vector<vector<bool>> graph(n, vector<bool>(n, false));
    for (auto i = 0; i < m; i++)
    {
        unsigned short a, b;
        std::cin >> a >> b;
        graph.at(a - 1).at(b - 1) = true;
        graph.at(b - 1).at(a - 1) = true;
    }

    unsigned short min_node;
    unsigned int min_kevin = (1ll << 4 * 8) - 1;
    for (auto i = 0; i < n; i++)
    {
        std::queue<unsigned short> q;
        vector<bool> visited(n, false);
        unsigned short count = 0;
        unsigned int now_kevin = 0;
        q.push(i);
        visited.at(i) = true;
        while (!q.empty())
        {
            count++;
            unsigned short q_size = q.size();
            for (auto j = 0; j < q_size; j++)
            {
                for (auto k = 0; k < n; k++)
                {
                    if (graph.at(q.front()).at(k) && !visited.at(k))
                    {
                        q.push(k);
                        visited.at(k) = true;
                        now_kevin += count;
                    }
                }
                q.pop();
            }
        }
        if (min_kevin > now_kevin)
        {
            min_kevin = now_kevin;
            min_node = i;
        }
    }
    std::cout << min_node + 1 << '\n';

    return 0;
}
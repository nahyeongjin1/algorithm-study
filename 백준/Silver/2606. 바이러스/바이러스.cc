/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2606                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2606                           #+#        #+#      #+#    */
/*   Solved: 2025/02/18 22:02:37 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <queue>

using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    short n, m;
    std::cin >> n >> m;

    vector<vector<bool>> graph(n, vector<bool>(n, false));

    for (auto i = 0; i < m; i++)
    {
        short input1, input2;
        std::cin >> input1 >> input2;
        graph.at(input1 - 1).at(input2 - 1) = true;
        graph.at(input2 - 1).at(input1 - 1) = true;
    }

    std::queue<short> q;
    std::vector<bool> visited(n, false);
    q.push(0);
    visited.at(0) = true;

    while (!q.empty())
    {
        short now = q.front();
        q.pop();

        for (auto i = 0; i < n; i++)
        {
            if (!visited.at(i) && graph.at(now).at(i))
            {
                visited.at(i) = true;
                q.push(i);
            }
        }
    }

    short infected = -1;
    for (auto i = visited.begin(); i != visited.end(); i++)
    {
        infected += (*i) ? 1 : 0;
    }

    std::cout << infected;

    return 0;
}

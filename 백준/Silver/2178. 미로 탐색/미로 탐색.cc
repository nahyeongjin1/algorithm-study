/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2178                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2178                           #+#        #+#      #+#    */
/*   Solved: 2025/02/24 21:50:00 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <queue>

using std::pair;
using std::queue;
using std::vector;

typedef unsigned short us;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    us n, m;
    std::cin >> n >> m;
    vector<vector<bool>> map(n, vector<bool>(m, false));
    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < m; j++)
        {
            char input;
            std::cin >> input;
            map.at(i).at(j) = input == '1' ? true : false;
        }
    }

    queue<pair<pair<us, us>, us>> q;
    q.push({{0, 0}, 1});
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited.at(0).at(0) = true;

    while (!q.empty())
    {
        us now_x = q.front().first.first;
        us now_y = q.front().first.second;
        us now_count = q.front().second;
        q.pop();
        if (now_x == m - 1 && now_y == n - 1)
        {
            std::cout << now_count << '\n';
            break;
        }
        if (now_x > 0 && map.at(now_y).at(now_x - 1) && !visited.at(now_y).at(now_x - 1))
        {
            q.push({{now_x - 1, now_y}, now_count + 1});
            visited.at(now_y).at(now_x - 1) = true;
        }
        if (now_y > 0 && map.at(now_y - 1).at(now_x) && !visited.at(now_y - 1).at(now_x))
        {
            q.push({{now_x, now_y - 1}, now_count + 1});
            visited.at(now_y - 1).at(now_x) = true;
        }
        if (now_x + 1 < m && map.at(now_y).at(now_x + 1) && !visited.at(now_y).at(now_x + 1))
        {
            q.push({{now_x + 1, now_y}, now_count + 1});
            visited.at(now_y).at(now_x + 1) = true;
        }
        if (now_y + 1 < n && map.at(now_y + 1).at(now_x) && !visited.at(now_y + 1).at(now_x))
        {
            q.push({{now_x, now_y + 1}, now_count + 1});
            visited.at(now_y + 1).at(now_x) = true;
        }
    }

    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2667                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2667                           #+#        #+#      #+#    */
/*   Solved: 2025/02/25 18:48:47 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using std::pair;
using std::stack;
using std::vector;

typedef unsigned short us;

bool Compare(const us &h1, const us &h2)
{
    return h1 < h2;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    us n;
    std::cin >> n;
    vector<vector<bool>> map(n, vector<bool>(n, false));
    vector<us> danji;

    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < n; j++)
        {
            char input;
            std::cin >> input;
            map.at(i).at(j) = input == '1' ? true : false;
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for (auto y = 0; y < n; y++)
    {
        for (auto x = 0; x < n; x++)
        {
            if (map.at(y).at(x) && !visited.at(y).at(x))
            {
                stack<pair<us, us>> s;
                us max_count = 1;
                s.push({x, y});
                visited.at(y).at(x) = true;
                while (!s.empty())
                {
                    us now_x = s.top().first;
                    us now_y = s.top().second;
                    s.pop();
                    if (now_x > 0 && !visited.at(now_y).at(now_x - 1) && map.at(now_y).at(now_x - 1))
                    {
                        visited.at(now_y).at(now_x - 1) = true;
                        s.push({now_x - 1, now_y});
                        max_count += 1;
                    }
                    if (now_y > 0 && !visited.at(now_y - 1).at(now_x) && map.at(now_y - 1).at(now_x))
                    {
                        visited.at(now_y - 1).at(now_x) = true;
                        s.push({now_x, now_y - 1});
                        max_count += 1;
                    }
                    if (now_x < n - 1 && !visited.at(now_y).at(now_x + 1) && map.at(now_y).at(now_x + 1))
                    {
                        visited.at(now_y).at(now_x + 1) = true;
                        s.push({now_x + 1, now_y});
                        max_count += 1;
                    }
                    if (now_y < n - 1 && !visited.at(now_y + 1).at(now_x) && map.at(now_y + 1).at(now_x))
                    {
                        visited.at(now_y + 1).at(now_x) = true;
                        s.push({now_x, now_y + 1});
                        max_count += 1;
                    }
                }
                danji.push_back(max_count);
            }
        }
    }

    std::sort(danji.begin(), danji.end(), Compare);
    std::cout << danji.size() << '\n';
    for (auto i = 0; i < danji.size(); i++)
    {
        std::cout << danji.at(i) << '\n';
    }

    return 0;
}
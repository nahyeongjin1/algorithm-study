/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1966                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1966                           #+#        #+#      #+#    */
/*   Solved: 2025/02/17 21:50:51 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    std::cin >> t;
    for (auto i = 0; i < t; i++)
    {
        std::vector<std::pair<short, short>> vec;
        short n, m;
        std::cin >> n >> m;

        for (auto j = 0; j < n; j++)
        {
            short input;
            std::cin >> input;
            vec.push_back({input, j});
        }

        for (auto j = 0; j < n; j++)
        {
            std::pair<short, short> max_pair = {0, 0};
            for (auto k = 0; k < n - j; k++)
            {
                if (vec.at(k).first > max_pair.first)
                {
                    max_pair.first = vec.at(k).first;
                    max_pair.second = vec.at(k).second;
                }
            }
            if (max_pair.second == m)
            {
                std::cout << j + 1 << '\n';
                break;
            }
            for (auto k = 0; k < n - j; k++)
            {
                if (vec.front().first == max_pair.first)
                {
                    vec.erase(vec.begin());
                    break;
                }
                std::pair<short, short> temp = vec.front();
                vec.erase(vec.begin());
                vec.push_back(temp);
            }
        }
    }

    return 0;
}
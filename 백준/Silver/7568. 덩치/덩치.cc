/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 7568                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/7568                           #+#        #+#      #+#    */
/*   Solved: 2025/02/16 17:47:41 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

bool compare(std::pair<short, short> p1, std::pair<short, short> p2)
{
    return p1.first < p2.first && p1.second < p2.second;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    short n, x, y;
    std::cin >> n;
    std::vector<std::pair<short, short>> vec(n);
    std::vector<short> output(n, 1);
    for (auto i = 0; i < n; i++)
    {
        std::cin >> x >> y;
        vec.at(i) = std::make_pair(x, y);
    }
    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            output.at(i) += compare(vec.at(i), vec.at(j)) ? 1 : 0;
        }
    }
    for (auto i = output.begin(); i != output.end(); i++)
    {
        std::cout << *i << ' ';
    }

    return 0;
}
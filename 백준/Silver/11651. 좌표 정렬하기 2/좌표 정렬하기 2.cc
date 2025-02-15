/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11651                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11651                          #+#        #+#      #+#    */
/*   Solved: 2025/02/15 18:25:25 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

bool Compare(std::pair<int, int> p1, std::pair<int, int> p2)
{
    if (p1.second == p2.second)
    {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> coordinates(n);

    for (auto i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        coordinates.at(i) = std::make_pair(x, y);
    }

    std::sort(coordinates.begin(), coordinates.end(), Compare);

    for (auto i = 0; i < n; i++)
    {
        std::cout << coordinates.at(i).first << ' ' << coordinates.at(i).second << '\n';
    }

    return 0;
}
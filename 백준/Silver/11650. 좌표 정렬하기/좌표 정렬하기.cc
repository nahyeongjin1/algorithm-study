/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11650                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11650                          #+#        #+#      #+#    */
/*   Solved: 2025/02/15 21:05:35 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

bool Compare(std::pair<int, int> p1, std::pair<int, int> p2)
{
    if (p1.first == p2.first)
    {
        return p1.second < p2.second;
    }
    return p1.first < p2.first;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n, x, y;
    std::cin >> n;
    std::vector<std::pair<int, int>> coordinates(n);

    for (auto i = 0; i < n; i++)
    {
        std::cin >> x >> y;
        coordinates.at(i) = std::make_pair(x, y);
    }
    std::sort(coordinates.begin(), coordinates.end(), Compare);

    for (auto i = coordinates.begin(); i < coordinates.end(); i++)
    {
        std::cout << i->first << ' ' << i->second << '\n';
    }

    return 0;
}
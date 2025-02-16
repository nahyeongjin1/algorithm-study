/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10816                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10816                          #+#        #+#      #+#    */
/*   Solved: 2025/02/16 16:10:44 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, input, output;
    std::map<int, int> map;
    std::map<int, int>::iterator position;

    std::cin >> n;
    for (auto i = 0; i < n; i++)
    {
        std::cin >> input;
        position = map.find(input);
        if (position == map.end())
        {
            map.insert(std::make_pair(input, 1));
        }
        else
        {
            position->second = position->second + 1;
        }
    }
    std::cin >> m;
    for (auto i = 0; i < m; i++)
    {
        std::cin >> input;
        position = map.find(input);
        output = position == map.end() ? 0 : position->second;
        std::cout << output << ' ';
    }

    return 0;
}
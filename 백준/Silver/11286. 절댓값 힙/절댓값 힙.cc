/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11286                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11286                          #+#        #+#      #+#    */
/*   Solved: 2025/02/28 21:20:56 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using std::pair;

typedef unsigned int ui;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    auto compare = [](pair<int, ui> p1, pair<int, ui> p2) -> bool
    {
        if (p1.second == p2.second)
        {
            return p1.first > p2.first;
        }
        return p1.second > p2.second;
    };

    std::vector<pair<int, ui>> vec;
    ui n;
    std::cin >> n;

    int input;
    while (n--)
    {
        std::cin >> input;
        if (input == 0)
        {
            if (vec.empty())
            {
                std::cout << 0 << '\n';
            }
            else
            {
                std::pop_heap(vec.begin(), vec.end(), compare);
                std::cout << vec.back().first << '\n';
                vec.pop_back();
            }
        }
        else
        {
            vec.push_back({input, std::abs(input)});
            std::push_heap(vec.begin(), vec.end(), compare);
        }
    }
    return 0;
}
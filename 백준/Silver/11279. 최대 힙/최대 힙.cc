/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11279                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11279                          #+#        #+#      #+#    */
/*   Solved: 2025/02/28 21:21:02 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

typedef unsigned int ui;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    ui n;
    std::cin >> n;

    std::vector<ui> vec;
    while (n--)
    {
        ui input;
        std::cin >> input;
        if (input == 0)
        {
            if (vec.empty())
            {
                std::cout << 0 << '\n';
            }
            else
            {
                std::pop_heap(vec.begin(), vec.end());
                std::cout << vec.back() << '\n';
                vec.pop_back();
            }
        }
        else
        {
            vec.push_back(input);
            std::push_heap(vec.begin(), vec.end());
        }
    }

    return 0;
}
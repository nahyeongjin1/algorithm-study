/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10989                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10989                          #+#        #+#      #+#    */
/*   Solved: 2025/02/15 21:30:56 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n, input;
    std::cin >> n;
    std::vector<int> vec(10000, 0);
    for (auto i = 0; i < n; i++)
    {
        std::cin >> input;
        vec.at(input - 1)++;
    }

    for (auto i = 0; i < 10000; i++)
    {
        for (auto j = 0; j < vec.at(i); j++)
        {
            std::cout << i + 1 << '\n';
        }
    }

    return 0;
}
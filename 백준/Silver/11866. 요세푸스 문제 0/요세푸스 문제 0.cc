/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11866                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11866                          #+#        #+#      #+#    */
/*   Solved: 2025/02/15 18:25:17 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    short n, k, index = 0;
    std::cin >> n >> k;
    std::vector<short> input(n), output(n);
    for (auto i = 0; i < n; i++)
    {
        input.at(i) = i + 1;
    }

    short count = 0;
    auto iterator = input.begin();

    while (input.size() != 0)
    {
        count++;
        if (count == k)
        {
            count = 0;
            output.at(index++) = *iterator;
            iterator = input.erase(iterator, iterator + 1) - 1;
        }
        if (++iterator == input.end())
        {
            iterator = input.begin();
        }
    }

    std::cout << '<';
    for (auto i = 0; i < output.size(); i++)
    {
        std::cout << output.at(i);
        if (i != output.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << '>';

    return 0;
}
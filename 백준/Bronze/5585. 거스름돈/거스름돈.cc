/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 5585                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/5585                           #+#        #+#      #+#    */
/*   Solved: 2025/03/04 20:59:53 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t coins[] = {500, 100, 50, 10, 5, 1};
    uint16_t cost, count = 0;

    std::cin >> cost;

    uint16_t change = 1000 - cost;
    for (const auto &coin : coins)
    {
        while (change / coin)
        {
            change -= coin;
            count++;
        }
    }
    std::cout << count << '\n';

    return 0;
}
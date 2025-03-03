/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1668                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1668                           #+#        #+#      #+#    */
/*   Solved: 2025/03/03 21:45:24 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n;
    std::cin >> n;

    std::vector<uint16_t> trophies(n, 0);
    for (uint16_t i = 0; i < n; i++)
    {
        std::cin >> trophies[i];
    }
    uint16_t l_max = 0, r_max = 0;
    uint16_t l_count = 0, r_count = 0;
    for (uint16_t i = 0; i < n; i++)
    {
        if (trophies[i] > l_max)
        {
            l_max = trophies[i];
            l_count++;
        }
        if (trophies[n - 1 - i] > r_max)
        {
            r_max = trophies[n - 1 - i];
            r_count++;
        }
    }
    std::cout << l_count << '\n'
              << r_count << '\n';

    return 0;
}
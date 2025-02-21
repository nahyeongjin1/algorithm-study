/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 17626                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/17626                          #+#        #+#      #+#    */
/*   Solved: 2025/02/21 20:59:31 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned short n;
    std::cin >> n;

    std::vector<unsigned short> dp(n + 1);
    dp.at(0) = 0;
    for (auto i = 1; i <= n; i++)
    {
        unsigned short min = dp.at(i - 1);
        for (auto j = 2; j * j <= i; j++)
        {
            min = std::min(min, dp.at(i - j * j));
        }
        dp.at(i) = min + 1;
    }
    std::cout << dp.at(n);

    return 0;
}
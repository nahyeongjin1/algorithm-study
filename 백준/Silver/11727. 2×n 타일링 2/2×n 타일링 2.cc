/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11727                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11727                          #+#        #+#      #+#    */
/*   Solved: 2025/02/20 23:20:26 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned short n;
    std::cin >> n;

    std::vector<unsigned short> dp(n);
    dp.at(0) = 1;
    if (n >= 2)
    {
        dp.at(1) = 3;
    }
    for (auto i = 2; i < n; i++)
    {
        dp.at(i) = (dp.at(i - 1) + 2 * dp.at(i - 2)) % 10007;
    }
    std::cout << dp.at(n - 1);

    return 0;
}

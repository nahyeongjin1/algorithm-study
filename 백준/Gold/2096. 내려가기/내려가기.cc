/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2096                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2096                           #+#        #+#      #+#    */
/*   Solved: 2025/03/28 22:17:43 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint32_t n; // 1 <= n <= 100,000
    std::cin >> n;

    uint16_t a, b, c;
    std::cin >> a >> b >> c;

    uint32_t max_dp[3] = {a, b, c};
    uint32_t min_dp[3] = {a, b, c};

    for (uint32_t i = 1; i < n; i++)
    {
        std::cin >> a >> b >> c;

        uint32_t new_max_0 = a + std::max(max_dp[0], max_dp[1]);
        uint32_t new_max_1 = b + std::max({max_dp[0], max_dp[1], max_dp[2]});
        uint32_t new_max_2 = c + std::max(max_dp[1], max_dp[2]);

        uint32_t new_min_0 = a + std::min(min_dp[0], min_dp[1]);
        uint32_t new_min_1 = b + std::min({min_dp[0], min_dp[1], min_dp[2]});
        uint32_t new_min_2 = c + std::min(min_dp[1], min_dp[2]);

        max_dp[0] = new_max_0;
        max_dp[1] = new_max_1;
        max_dp[2] = new_max_2;
        min_dp[0] = new_min_0;
        min_dp[1] = new_min_1;
        min_dp[2] = new_min_2;
    }

    uint32_t max_result = std::max({max_dp[0], max_dp[1], max_dp[2]});
    uint32_t min_result = std::min({min_dp[0], min_dp[1], min_dp[2]});

    std::cout << max_result << ' ' << min_result << '\n';

    return 0;
}
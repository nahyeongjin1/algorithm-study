/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1149                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1149                           #+#        #+#      #+#    */
/*   Solved: 2025/03/04 08:49:57 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n; // 2 <= n <= 1,000
    uint16_t r, g, b;

    std::cin >> n;
    vector<vector<uint32_t>> dp(n, vector<uint32_t>(3, 0));

    // 첫 번째 집집
    std::cin >> r >> g >> b;
    dp[0][0] = r;
    dp[0][1] = g;
    dp[0][2] = b;

    // 동적 계획법
    for (uint16_t i = 1; i < n; i++)
    {
        std::cin >> r >> g >> b;
        dp[i][0] = std::min(dp[i - 1][1], dp[i - 1][2]) + r;
        dp[i][1] = std::min(dp[i - 1][2], dp[i - 1][0]) + g;
        dp[i][2] = std::min(dp[i - 1][0], dp[i - 1][1]) + b;
    }
    std::cout << std::min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << '\n';

    return 0;
}
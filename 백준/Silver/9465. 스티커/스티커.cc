/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9465                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9465                           #+#        #+#      #+#    */
/*   Solved: 2025/06/24 09:47:23 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint32_t t;
    std::cin >> t;

    for (uint32_t i = 0; i < t; i++)
    {
        uint32_t n;
        std::cin >> n;

        // n이 1인 경우를 예외처리하기 싫음 + 마지막에 4개 비교하기 싫음 -> n+1
        vector<vector<uint32_t>> dp(2, vector<uint32_t>(n + 1, 0));

        for (uint32_t j = 0; j < 2 * n; j++)
        {
            std::cin >> dp[j / n][j % n];
        }

        /** 상당히 dp스러운 문젠데
         * 0번째 열은 스스로의 값으로 할당
         * k번쨰 열은 반드시 스스로의 값을 더하는 방식
         **/

        dp[0][1] += dp[1][0];
        dp[1][1] += dp[0][0];

        for (uint32_t col = 2; col < n + 1; col++)
        {
            dp[0][col] += std::max(dp[1][col - 1], dp[1][col - 2]);
            dp[1][col] += std::max(dp[0][col - 1], dp[0][col - 2]);
        }

        std::cout << std::max(dp[0][n], dp[1][n]) << '\n';
    }
}
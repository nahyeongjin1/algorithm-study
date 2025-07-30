/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 12865                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/12865                          #+#        #+#      #+#    */
/*   Solved: 2025/07/28 11:52:57 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

using std::pair;
using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n; // [1, 100]
    uint32_t k; // [1, 100000]
    std::cin >> n >> k;

    // dp[j]: 배낭의 용량이 j일 때의 최대 가치
    vector<uint32_t> dp(k + 1, 0);

    // n회 순회
    for (uint16_t i = 0; i < n; i++)
    {
        uint32_t w;
        uint16_t v;
        std::cin >> w >> v;

        for (int32_t j = k; j >= w; j--)
        {
            dp[j] = std::max(dp[j], dp[j - w] + v);
        }
    }

    std::cout << dp[k] << '\n';

    return 0;
}
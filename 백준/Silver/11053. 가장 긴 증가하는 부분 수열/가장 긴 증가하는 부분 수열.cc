/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11053                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11053                          #+#        #+#      #+#    */
/*   Solved: 2025/07/08 18:36:56 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

using std::max_element;
using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n;
    std::cin >> n;

    vector<uint16_t> a(n);
    for (uint16_t i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    vector<uint16_t> dp(n, 1);

    for (uint16_t i = 1; i < n; i++)
    {
        for (uint16_t j = 0; j < i; j++)
        {
            dp[i] = a[j] < a[i] ? std::max(dp[i], uint16_t(dp[j] + 1)) : dp[i];
        }
    }

    std::cout << *max_element(dp.begin(), dp.end()) << '\n';

    return 0;
}
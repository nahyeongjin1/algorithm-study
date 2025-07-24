/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11660                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11660                          #+#        #+#      #+#    */
/*   Solved: 2025/07/24 14:45:12 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using std::vector;

/**
 * Prefix Sum
 */
int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n;
    uint32_t m;

    std::cin >> n >> m;

    vector<vector<uint32_t>> table(n + 1, vector<uint32_t>(n + 1, 0));

    for (uint16_t i = 1; i <= n; i++)
    {
        for (uint16_t j = 1; j <= n; j++)
        {
            uint16_t input;
            std::cin >> input;
            table[i][j] = input + table[i - 1][j] + table[i][j - 1] - table[i - 1][j - 1];
        }
    }

    while (m--)
    {
        uint16_t x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        std::cout << table[x2][y2] - table[x1 - 1][y2] - table[x2][y1 - 1] + table[x1 - 1][y1 - 1] << '\n';
    }

    return 0;
}
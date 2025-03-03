/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 18111                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/18111                          #+#        #+#      #+#    */
/*   Solved: 2025/03/02 16:46:00 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint32_t n, m; // 1 <= n, m <= 500
    uint32_t b;    // 0 <= b <= 64,000,000
    std::cin >> n >> m >> b;

    uint16_t max = 0;
    uint16_t min = UINT16_MAX;
    uint16_t input;

    vector<vector<uint16_t>> site(n, vector<uint16_t>(m, 0));
    for (uint16_t i = 0; i < n; i++)
    {
        for (uint16_t j = 0; j < m; j++)
        {
            std::cin >> input;
            max = std::max(max, input);
            min = std::min(min, input);
            site[i][j] = input;
        }
    }

    uint32_t min_time = UINT32_MAX;
    uint16_t min_floor;
    // h는 목표 높이
    for (uint16_t h = min; h <= max; h++)
    {
        int32_t inventory = b;
        uint32_t elapsed_time = 0;
        // i는 가로
        for (uint16_t i = 0; i < n; i++)
        {
            // j는 세로
            for (uint16_t j = 0; j < m; j++)
            {
                uint16_t cur = site[i][j];
                if (cur > h)
                {
                    uint16_t gap = cur - h;
                    inventory += gap;
                    elapsed_time += 2 * gap;
                }
                else if (cur < h)
                {
                    uint16_t gap = h - cur;
                    inventory -= gap;
                    elapsed_time += gap;
                }
            }
        }
        if (inventory >= 0)
        {
            if (min_time >= elapsed_time)
            {
                min_time = elapsed_time;
                min_floor = h;
            }
        }
    }
    std::cout << min_time << ' ' << min_floor << '\n';

    return 0;
}
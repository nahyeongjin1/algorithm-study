/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 12851                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/12851                          #+#        #+#      #+#    */
/*   Solved: 2025/07/25 19:54:58 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <queue>
#include <array>
#include <algorithm>

using std::array;
using std::pair;
using std::queue;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    constexpr uint32_t SIZE = 100001;
    constexpr uint32_t MAX = UINT32_MAX;

    uint32_t subin, dongsaeng;
    std::cin >> subin >> dongsaeng;

    array<uint32_t, SIZE> min_time;   // 해당 위치까지 도달하는데 걸린 최소 시간
    array<uint32_t, SIZE> ways = {0}; // 최단 시간에 각 위치까지 도달하는 방법의 수
    queue<pair<int32_t, uint32_t>> q; // {pos, cnt}

    std::fill(min_time.begin(), min_time.end(), MAX);
    min_time[subin] = 0;
    ways[subin] = 1;
    q.push({subin, 0});

    while (!q.empty())
    {
        auto [pos, cnt] = q.front();
        q.pop();

        if (min_time[pos] < cnt)
            continue;

        for (int32_t next_pos : {pos - 1, pos + 1, pos * 2})
        {
            if (next_pos >= 0 && next_pos <= SIZE - 1)
            {
                // 첫 방문 or 더 빠른 경로
                if (min_time[next_pos] > cnt + 1)
                {
                    min_time[next_pos] = cnt + 1;
                    ways[next_pos] = ways[pos];
                    q.push({next_pos, cnt + 1});
                }
                // 최단 시간과 동일한 시간의 다른 경로
                else if (min_time[next_pos] == cnt + 1)
                {
                    ways[next_pos] += ways[pos];
                }
            }
        }
    }

    std::cout << min_time[dongsaeng] << '\n'
              << ways[dongsaeng] << '\n';

    return 0;
}
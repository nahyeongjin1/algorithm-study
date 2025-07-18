/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11404                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11404                          #+#        #+#      #+#    */
/*   Solved: 2025/07/09 20:23:20 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using std::vector;

/**
 * @brief 플로이드-워셜 알고리즘(Floyd-Warshall Algorithm)
 */
int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    constexpr uint32_t INF = UINT32_MAX;

    uint16_t n; // [2, 100]
    uint32_t m; // [1, 100,000]

    std::cin >> n >> m;

    vector<vector<uint32_t>> dist(n, vector<uint32_t>(n, INF)); // [1, 10,000,000)
    for (uint16_t i = 0; i < n; i++)
    {
        dist[i][i] = 0;
    }

    for (uint32_t i = 0; i < m; i++)
    {
        uint16_t from, to;
        uint32_t fee; // [1, 100,000]
        std::cin >> from >> to >> fee;
        if (fee < dist[from - 1][to - 1])
        {
            dist[from - 1][to - 1] = fee;
        }
    }

    // 거쳐가는 노드
    for (uint16_t i = 0; i < n; i++)
    {
        // 출발 노드
        for (uint16_t j = 0; j < n; j++)
        {
            // 도착 노드
            for (uint16_t k = 0; k < n; k++)
            {
                if (dist[j][i] != INF && dist[i][k] != INF)
                    dist[j][k] = std::min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }

    for (const vector<uint32_t> &vec : dist)
    {
        for (uint16_t i = 0; i < n; i++)
        {
            uint32_t cost = (vec[i] == INF) ? 0 : vec[i];
            std::cout << (i == 0 ? "" : " ") << cost;
        }
        std::cout << '\n';
    }

    return 0;
}
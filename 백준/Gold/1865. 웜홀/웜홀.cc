/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1865                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1865                           #+#        #+#      #+#    */
/*   Solved: 2025/03/17 18:20:19 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using std::vector;

struct edge
{
    uint16_t u, v;
    int32_t w; // u -> v로 가는 간선, 가중치 w
    edge(uint16_t a, uint16_t b, int32_t c) : u(a), v(b), w(c) {}
};

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t tc; // 1 <= tc <= 5
    std::cin >> tc;
    while (tc--)
    {
        /*
        1 <= n <= 500
        1 <= m <= 2,500
        1 <= w <= 200
         */
        uint16_t n, m, w;
        std::cin >> n >> m >> w;
        vector<edge> edges;

        // 도로: 양방향, 가중치는 양의 정수
        for (int i = 0; i < m; i++)
        {
            uint16_t s, e, t; // 0 <= t <= 10,000
            std::cin >> s >> e >> t;
            s--;
            e--;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }

        // 웜홀: 단방향, 가중치는 음수로 적용 (시간 감소)
        for (int i = 0; i < w; i++)
        {
            int32_t s, e, t;
            std::cin >> s >> e >> t;
            edges.push_back({s - 1, e - 1, -t});
        }

        // 모든 정점을 시작점으로 고려하기 위해, dist를 모두 0으로 초기화한다.
        constexpr int32_t INF = INT32_MAX;
        vector<int32_t> dist(n, 0);

        bool can = false;
        // 총 n-1번 반복 (최단 경로 갱신)
        for (int i = 0; i < n - 1; i++)
        {
            bool updated = false;
            for (const edge &e : edges)
            {
                if (dist[e.u] + e.w < dist[e.v])
                {
                    dist[e.v] = dist[e.u] + e.w;
                    updated = true;
                }
            }
            // 만약 갱신이 없으면 더 이상 업데이트할 필요 없음
            if (!updated)
                break;
        }

        // 음의 사이클 존재 여부 체크: 한 번 더 갱신이 가능한지 확인
        for (const edge &e : edges)
        {
            if (dist[e.u] + e.w < dist[e.v])
            {
                can = true;
                break;
            }
        }

        std::cout << (can ? "YES" : "NO") << "\n";
    }

    return 0;
}

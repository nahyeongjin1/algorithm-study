/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2638                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2638                           #+#        #+#      #+#    */
/*   Solved: 2025/04/06 19:40:22 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>

using std::pair;
using std::queue;
using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n, m; // 5 <= n, m <= 100
    uint16_t result = 0;
    std::cin >> n >> m;

    // 치즈들 담을 큐
    queue<pair<int16_t, int16_t>> cheeze;
    vector<vector<uint16_t>> paper(n, vector<uint16_t>(m));
    for (uint16_t i = 0; i < n; i++)
    {
        uint16_t input;
        for (uint16_t j = 0; j < m; j++)
        {
            std::cin >> input;
            paper[i][j] = input;
            if (input == 1)
                cheeze.push({i, j});
        }
    }

    // (0,0)을 기점으로 bfs로 0을 전부 2(외부공기)로 변경
    // 이게 가능한 이유는 가장자리에는 치즈가 놓이지 않음
    queue<pair<int16_t, int16_t>> outer;
    outer.push({0, 0});

    pair<int16_t, int16_t> diff[4] = {{-1, 0},
                                      {1, 0},
                                      {0, -1},
                                      {0, 1}};

    while (!cheeze.empty())
    {
        result++;
        while (!outer.empty())
        {
            auto [ny, nx] = outer.front();
            outer.pop();
            paper[ny][nx] = 2;

            for (auto [dy, dx] : diff)
            {
                int16_t y = ny + dy;
                int16_t x = nx + dx;
                if (y < 0 || y >= n || x < 0 || x >= m)
                    continue;
                if (paper[y][x] == 0)
                {
                    paper[y][x] = 3; // queue에 들어감을 표시
                    outer.push({y, x});
                }
            }
        }

        uint16_t loop = cheeze.size();
        for (uint16_t i = 0; i < loop; i++)
        {
            uint16_t count = 0;
            auto [ny, nx] = cheeze.front();
            cheeze.pop();
            for (auto [dy, dx] : diff)
            {
                if (paper[ny + dy][nx + dx] == 2)
                    count++;
            }
            if (count >= 2)
                outer.push({ny, nx});
            else
                cheeze.push({ny, nx});
        }
    }

    std::cout << result << '\n';
    return 0;
}
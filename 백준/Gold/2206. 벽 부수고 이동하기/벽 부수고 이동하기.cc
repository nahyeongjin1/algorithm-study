/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2206                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2206                           #+#        #+#      #+#    */
/*   Solved: 2025/03/28 22:17:37 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>

using std::pair;
using std::queue;
using std::vector;

struct state
{
    int16_t y;
    int16_t x;
    uint16_t wall;
    state(int16_t a, int16_t b, uint16_t c) : y(a), x(b), wall(c) {}
};

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint16_t n, m; // 1 <= n, m <= 1,000
    std::cin >> n >> m;

    vector<vector<bool>> map(n, vector<bool>(m, false));
    for (uint16_t r = 0; r < n; r++)
    {
        for (uint16_t c = 0; c < m; c++)
        {
            uint8_t input;
            std::cin >> input;
            map[r][c] = input == '1' ? true : false;
        }
    }

    pair<int16_t, int16_t> diff[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    vector<vector<vector<uint32_t>>> dist(n, vector<vector<uint32_t>>(m, vector<uint32_t>(2, 0)));
    queue<state> q;

    dist[0][0][0] = 1;
    q.push({0, 0, 0});

    int32_t min_dist = -1;
    while (!q.empty())
    {
        auto [cur_y, cur_x, wall] = q.front();
        q.pop();
        if (cur_y == n - 1 && cur_x == m - 1)
        {
            min_dist = dist[cur_y][cur_x][wall];
            break;
        }
        for (const auto &[dy, dx] : diff)
        {
            int16_t ny = cur_y + dy;
            int16_t nx = cur_x + dx;
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;

            if (!map[ny][nx] && dist[ny][nx][wall] == 0)
            {
                dist[ny][nx][wall] = dist[cur_y][cur_x][wall] + 1;
                q.push({ny, nx, wall});
            }

            if (map[ny][nx] && wall == 0 && dist[ny][nx][1] == 0)
            {
                dist[ny][nx][1] = dist[cur_y][cur_x][wall] + 1;
                q.push({ny, nx, 1});
            }
        }
    }

    std::cout << min_dist << '\n';

    return 0;
}
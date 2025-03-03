/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 21736                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/21736                          #+#        #+#      #+#    */
/*   Solved: 2025/03/03 17:16:26 by skgudwls      ###          ###   ##.kr    */
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

    uint16_t n, m;
    std::cin >> n >> m;

    vector<vector<char>> campus(n, vector<char>(m, 'O'));
    queue<pair<int16_t, int16_t>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (uint16_t i = 0; i < n; i++)
    {
        for (uint16_t j = 0; j < m; j++)
        {
            char input;
            std::cin >> input;
            campus[i][j] = input;
            if (input == 'I')
            {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    vector<pair<int8_t, int8_t>> d = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    uint32_t friends = 0;
    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();
        if (campus[y][x] == 'P')
        {
            friends++;
        }
        for (const auto &[dy, dx] : d)
        {
            int16_t ny = y + dy;
            int16_t nx = x + dx;
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            {
                continue;
            }
            if (campus[ny][nx] == 'X' || visited[ny][nx])
            {
                continue;
            }
            q.push({ny, nx});
            visited[ny][nx] = true;
        }
    }
    std::cout << (friends == 0 ? "TT" : std::to_string(friends)) << '\n';
    return 0;
}
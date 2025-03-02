/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14500                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14500                          #+#        #+#      #+#    */
/*   Solved: 2025/03/01 20:39:31 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using std::pair;
using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    u_short n, m; // 4 <= n, m <= 500
    std::cin >> n >> m;

    // n x m
    vector<vector<u_short>> paper(n, vector<u_short>(m, 0));

    // input paper
    for (u_short i = 0; i < n; i++)
    {
        for (u_short j = 0; j < m; j++)
        {
            std::cin >> paper[i][j];
        }
    }

    vector<vector<pair<short, short>>> tetrominoes = {
        {{0, 1}, {0, 2}, {0, 3}},
        {{1, 0}, {2, 0}, {3, 0}},
        {{0, 1}, {1, 0}, {1, 1}},
        {{0, 1}, {0, 2}, {1, 0}},
        {{0, 1}, {0, 2}, {1, 1}},
        {{0, 1}, {0, 2}, {1, 2}},
        {{0, 1}, {0, 2}, {-1, 0}},
        {{0, 1}, {0, 2}, {-1, 1}},
        {{0, 1}, {0, 2}, {-1, 2}},
        {{1, 0}, {2, 0}, {0, 1}},
        {{1, 0}, {2, 0}, {1, 1}},
        {{1, 0}, {2, 0}, {2, 1}},
        {{1, 0}, {2, 0}, {0, -1}},
        {{1, 0}, {2, 0}, {1, -1}},
        {{1, 0}, {2, 0}, {2, -1}},
        {{0, 1}, {-1, 1}, {-1, 2}},
        {{0, 1}, {1, 1}, {1, 2}},
        {{1, 0}, {1, -1}, {2, -1}},
        {{1, 0}, {1, 1}, {2, 1}},
    };
    u_short max = 0;

    for (short i = 0; i < n; i++)
    {
        for (short j = 0; j < m; j++)
        {
            for (auto &shape : tetrominoes)
            {
                u_short sum = paper[i][j];
                bool valid = true;
                for (auto [dy, dx] : shape)
                {
                    short ny = i + dy;
                    short nx = j + dx;
                    if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                    {
                        valid = false;
                        break;
                    }
                    sum += paper[ny][nx];
                }
                if (valid)
                {
                    max = std::max(max, sum);
                }
            }
        }
    }

    std::cout << max << '\n';

    return 0;
}
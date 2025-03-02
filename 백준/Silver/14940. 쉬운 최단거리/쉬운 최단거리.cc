/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14940                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14940                          #+#        #+#      #+#    */
/*   Solved: 2025/03/02 14:40:17 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <queue>

using std::pair;
using std::queue;
using std::vector;

typedef struct Node
{
    short y;
    short x;
    u_int count;
    Node(short a, short b, u_int c) : y(a), x(b), count(c) {}
} node;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    u_short n, m; // 2 <= n, m <= 1000
    std::cin >> n >> m;

    vector<vector<u_short>> map(n, vector<u_short>(m, 0));
    vector<vector<int>> distance(n, vector<int>(m, -1));
    queue<node> q;
    for (u_short i = 0; i < n; i++)
    {
        for (u_short j = 0; j < m; j++)
        {
            std::cin >> map[i][j];
            if (map[i][j] == 2)
            {
                q.push({i, j, 0});
                distance[i][j] = 0;
            }
            else if (map[i][j] == 0)
            {
                distance[i][j] = 0;
            }
        }
    }

    vector<pair<short, short>> var = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}};

    while (!q.empty())
    {
        auto [y, x, count] = q.front();
        count++;
        q.pop();
        for (auto [dy, dx] : var)
        {
            short ny = y + dy;
            short nx = x + dx;
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            {
                continue;
            }
            if (distance[ny][nx] == -1 && map[ny][nx])
            {
                q.push({ny, nx, count});
                distance[ny][nx] = count;
            }
        }
    }
    for (u_short i = 0; i < n; i++)
    {
        for (u_short j = 0; j < m; j++)
        {
            std::cout << (j ? " " : "") << distance[i][j];
        }
        std::cout << '\n';
    }
    return 0;
}
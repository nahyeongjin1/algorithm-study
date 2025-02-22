/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1012                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1012                           #+#        #+#      #+#    */
/*   Solved: 2025/02/21 20:59:24 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using std::vector;

short dx[4] = {0, 0, 1, -1};
short dy[4] = {1, -1, 0, 0};

void dfs(short x, short y, short m, short n, vector<vector<bool>> &field)
{
    field.at(y).at(x) = false;
    for (short i = 0; i < 4; i++)
    {
        short ny = y + dy[i];
        short nx = x + dx[i];
        if (ny >= 0 && ny < n && nx >= 0 && nx < m && field.at(ny).at(nx))
        {
            dfs(nx, ny, m, n, field);
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int t = 0;
    std::cin >> t;

    while (t--)
    {
        int m, n, k;
        std::cin >> m >> n >> k;

        vector<vector<bool>> field(n, vector<bool>(m, false));
        for (int i = 0; i < k; i++)
        {
            int x, y;
            std::cin >> x >> y;
            field.at(y).at(x) = true;
        }

        int count = 0;
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if (field.at(y).at(x))
                {
                    dfs(x, y, m, n, field);
                    count++;
                }
            }
        }
        std::cout << count << "\n";
    }

    return 0;
}
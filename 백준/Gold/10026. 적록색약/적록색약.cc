/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10026                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10026                          #+#        #+#      #+#    */
/*   Solved: 2025/02/28 21:21:10 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stack>

using std::pair;
using std::stack;
using std::vector;

typedef unsigned short us;

us calculate_area(bool blindness, const vector<vector<char>> &pic)
{
    us n = pic.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    us count = 0;

    // blindness 여부에 따른 구역 판단 람다 함수
    auto is_same_region = [&](char c1, char c2) -> bool
    {
        if (blindness)
        {
            return (c1 == 'B') ? (c2 == 'B') : (c2 != 'B');
        }
        else
        {
            return c1 == c2;
        }
    };

    short dy[] = {-1, 1, 0, 0};
    short dx[] = {0, 0, -1, 1};

    for (us i = 0; i < n; i++)
    {
        for (us j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                count++;
                stack<pair<us, us>> st;
                st.push({i, j});
                visited[i][j] = true;

                while (!st.empty())
                {
                    pair<us, us> cur = st.top();
                    us y = cur.first;
                    us x = cur.second;
                    st.pop();
                    for (int d = 0; d < 4; d++)
                    {
                        int ny = y + dy[d];
                        int nx = x + dx[d];
                        if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                            continue;
                        if (!visited[ny][nx] && is_same_region(pic[y][x], pic[ny][nx]))
                        {
                            visited[ny][nx] = true;
                            st.push({ny, nx});
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    us n;
    std::cin >> n;
    vector<vector<char>> pic(n, vector<char>(n, ' '));

    for (us i = 0; i < n; i++)
    {
        for (us j = 0; j < n; j++)
        {
            std::cin >> pic[i][j];
        }
    }

    std::cout << calculate_area(false, pic) << ' ' << calculate_area(true, pic) << '\n';

    return 0;
}

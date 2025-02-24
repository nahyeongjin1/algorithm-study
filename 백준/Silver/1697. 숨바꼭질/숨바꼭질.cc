/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1697                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1697                           #+#        #+#      #+#    */
/*   Solved: 2025/02/24 19:51:18 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>
#include <vector>

using std::pair;
using std::queue;
using std::vector;
typedef unsigned int ui;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    const ui MAX = 100000u;
    ui n, k;
    std::cin >> n >> k;

    queue<pair<ui, ui>> q;
    q.push({n, 0});

    vector<bool> visited(MAX + 1, false);
    visited.at(n) = true;

    while (!q.empty())
    {
        ui now = q.front().first;
        ui cnt = q.front().second;
        q.pop();
        if (now == k)
        {
            std::cout << cnt << '\n';
            break;
        }
        if (now > 0 && !visited.at(now - 1))
        {
            q.push({now - 1, cnt + 1});
            visited.at(now - 1) = true;
        }
        if (now + 1 <= MAX && !visited.at(now + 1))
        {
            q.push({now + 1, cnt + 1});
            visited.at(now + 1) = true;
        }
        if (now * 2 <= MAX && !visited.at(now * 2))
        {
            q.push({now * 2, cnt + 1});
            visited.at(now * 2) = true;
        }
    }

    return 0;
}
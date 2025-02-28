/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9019                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9019                           #+#        #+#      #+#    */
/*   Solved: 2025/02/26 16:31:49 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>
#include <vector>

typedef unsigned short us;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    constexpr us MAX = 10000;

    us t;
    std::cin >> t;

    while (t--)
    {
        us a, b;
        std::cin >> a >> b;

        std::queue<us> q;
        std::vector<bool> visited(MAX, false);
        std::vector<us> parent(MAX, MAX);
        std::vector<char> op(MAX, ' ');

        q.push(a);
        visited[a] = true;

        while (!q.empty())
        {
            us cur = q.front();
            q.pop();
            if (cur == b)
            {
                break;
            }

            // D
            us next = (cur * 2) % MAX;
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
                op[next] = 'D';
                parent[next] = cur;
            }
            // S
            next = (cur == 0) ? MAX - 1 : cur - 1;
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
                op[next] = 'S';
                parent[next] = cur;
            }
            // L
            next = (cur / 1000) + (cur % 1000) * 10;
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
                op[next] = 'L';
                parent[next] = cur;
            }
            // R
            next = (cur % 10) * 1000 + (cur / 10);
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
                op[next] = 'R';
                parent[next] = cur;
            }
        }
        std::string result;
        for (auto cur = b; cur != a; cur = parent[cur])
        {
            result.push_back(op[cur]);
        }
        for (auto i = result.rbegin(); i != result.rend(); i++)
        {
            std::cout << *i;
        }
        std::cout << '\n';
    }

    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1260                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1260                           #+#        #+#      #+#    */
/*   Solved: 2025/02/21 20:59:16 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    short n, m, v;
    std::cin >> n >> m >> v;
    vector<vector<bool>> graph(n, vector<bool>(n, false));
    for (auto i = 0; i < m; i++)
    {
        short a, b;
        std::cin >> a >> b;
        graph.at(a - 1).at(b - 1) = true;
        graph.at(b - 1).at(a - 1) = true;
    }

    // DFS
    std::stack<short> s;
    s.push(v);
    vector<bool> s_visited(n, false);
    s_visited.at(v - 1) = true;
    std::cout << s.top();
    while (!s.empty())
    {
        int i;
        for (i = 0; i < n; i++)
        {
            if (graph.at(s.top() - 1).at(i) && !s_visited.at(i))
            {
                s.push(i + 1);
                s_visited.at(i) = true;
                std::cout << ' ' << s.top();
                break;
            }
        }
        if (i != n)
        {
            continue;
        }
        else
        {
            s.pop();
        }
    }
    std::cout << '\n';

    // BFS
    std::queue<short> q;
    q.push(v);
    vector<bool> q_visited(n, false);
    q_visited.at(v - 1) = true;
    bool first = true;
    while (!q.empty())
    {
        for (auto i = 0; i < n; i++)
        {
            if (graph.at(q.front() - 1).at(i) && !q_visited.at(i))
            {
                q.push(i + 1);
                q_visited.at(i) = true;
            }
        }
        if (!first)
        {
            std::cout << ' ';
        }
        std::cout << q.front();
        first = false;
        q.pop();
    }

    return 0;
}
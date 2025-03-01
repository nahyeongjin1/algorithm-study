/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11724                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11724                          #+#        #+#      #+#    */
/*   Solved: 2025/03/01 19:57:08 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <vector>

using std::stack;
using std::vector;

using us = unsigned short;
using ui = unsigned int;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    us n;
    ui m;
    std::cin >> n >> m;

    vector<vector<us>> adj_list(n);
    vector<bool> visited(n, false);

    while (m--)
    {
        us u, v;
        std::cin >> u >> v;
        adj_list[u - 1].push_back(v - 1);
        adj_list[v - 1].push_back(u - 1);
    }

    stack<us> st;
    us connected_component = 0;

    for (us i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            st.push(i);
            visited[i] = true;
            connected_component++;
            while (!st.empty())
            {
                us cur = st.top();
                st.pop();
                for (auto next : adj_list[cur])
                {
                    if (!visited[next])
                    {
                        st.push(next);
                        visited[next] = true;
                    }
                }
            }
        }
    }
    std::cout << connected_component << '\n';
    return 0;
}
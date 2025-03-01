/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11403                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11403                          #+#        #+#      #+#    */
/*   Solved: 2025/03/01 19:10:20 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stack>

using std::pair;
using std::stack;
using std::vector;

typedef unsigned short us;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned short n;
    std::cin >> n;

    vector<vector<us>> adj_list(n);

    us input;
    for (us i = 0; i < n; i++)
    {
        for (us j = 0; j < n; j++)
        {
            std::cin >> input;
            if (input == 1)
            {
                adj_list[i].push_back(j);
            }
        }
    }

    for (us i = 0; i < n; i++)
    {
        vector<bool> visited(n, false);
        std::stack<us> st;

        for (auto next : adj_list[i])
        {
            st.push(next);
            visited[next] = true;
        }

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

        for (us j = 0; j < n; j++)
        {
            std::cout << (j ? " " : "") << visited[j];
        }
        std::cout << '\n';
    }

    return 0;
}
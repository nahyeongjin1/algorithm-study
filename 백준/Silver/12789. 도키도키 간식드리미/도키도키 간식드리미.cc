/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 12789                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/12789                          #+#        #+#      #+#    */
/*   Solved: 2025/03/17 21:03:03 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <stack>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::stack<uint16_t> st;
    uint16_t n, cur = 1;
    std::cin >> n;

    for (uint16_t i = 0; i < n; i++)
    {
        uint16_t input;
        if (!st.empty() && st.top() == cur)
        {
            cur++;
            i--;
            st.pop();
            continue;
        }
        std::cin >> input;
        if (input == cur)
        {
            cur++;
        }
        else
        {
            st.push(input);
        }
    }
    bool can = true;
    while (!st.empty())
    {
        if (st.top() == cur)
        {
            cur++;
            st.pop();
        }
        else
        {
            can = false;
            break;
        }
    }
    std::cout << (can ? "Nice" : "Sad") << '\n';

    return 0;
}
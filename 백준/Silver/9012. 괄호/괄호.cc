/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9012                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9012                           #+#        #+#      #+#    */
/*   Solved: 2025/02/16 16:56:18 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    std::string input, output;

    std::cin >> t;
    for (auto i = 0; i < t; i++)
    {
        std::stack<char> stack;

        std::cin >> input;
        output = "YES";
        for (auto j = input.begin(); j != input.end(); j++)
        {
            if (*j == '(')
            {
                stack.push('(');
            }
            else
            {
                if (!stack.empty())
                {
                    stack.pop();
                }
                else
                {
                    output = "NO";
                    break;
                }
            }
        }
        if (!stack.empty())
        {
            output = "NO";
        }
        std::cout << output << '\n';
    }

    return 0;
}
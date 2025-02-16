/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10773                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10773                          #+#        #+#      #+#    */
/*   Solved: 2025/02/16 16:56:23 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int k, input;
    unsigned int output = 0;
    std::stack<int> stack;

    std::cin >> k;
    for (auto i = 0; i < k; i++)
    {
        std::cin >> input;
        if (input == 0)
        {
            stack.pop();
        }
        else
        {
            stack.push(input);
        }
    }

    while (!stack.empty())
    {
        output += stack.top();
        stack.pop();
    }

    std::cout << output;

    return 0;
}
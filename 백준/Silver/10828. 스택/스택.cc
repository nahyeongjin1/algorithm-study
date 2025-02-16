/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10828                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10828                          #+#        #+#      #+#    */
/*   Solved: 2025/02/16 16:10:51 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::stack<int> stack;
    std::string command, output;
    short n;
    int x;

    std::cin >> n;
    for (auto i = 0; i < n; i++)
    {
        std::cin >> command;
        if (command == "push")
        {
            std::cin >> x;
            stack.push(x);
        }
        else
        {
            if (command == "pop")
            {
                if (stack.empty())
                {
                    output = "-1";
                }
                else
                {
                    output = std::to_string(stack.top());
                    stack.pop();
                }
            }
            else if (command == "size")
            {
                output = std::to_string(stack.size());
            }
            else if (command == "empty")
            {
                output = stack.empty() ? "1" : "0";
            }
            else if (command == "top")
            {
                if (stack.empty())
                {
                    output = "-1";
                }
                else
                {
                    output = std::to_string(stack.top());
                }
            }
            std::cout << output << '\n';
        }
    }

    return 0;
}
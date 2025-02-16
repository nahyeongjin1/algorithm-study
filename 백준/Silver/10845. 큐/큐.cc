/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10845                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10845                          #+#        #+#      #+#    */
/*   Solved: 2025/02/16 16:10:59 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::queue<int> queue;
    std::string input, output;
    int x;
    short n;

    std::cin >> n;
    for (auto i = 0; i < n; i++)
    {
        std::cin >> input;
        if (input == "push")
        {
            std::cin >> x;
            queue.push(x);
        }
        else
        {
            if (input == "pop")
            {
                if (queue.empty())
                {
                    output = "-1";
                }
                else
                {
                    output = std::to_string(queue.front());
                    queue.pop();
                }
            }
            else if (input == "size")
            {
                output = std::to_string(queue.size());
            }
            else if (input == "empty")
            {
                output = queue.empty() ? "1" : "0";
            }
            else if (input == "front")
            {
                if (queue.empty())
                {
                    output = "-1";
                }
                else
                {
                    output = std::to_string(queue.front());
                }
            }
            else if (input == "back")
            {
                if (queue.empty())
                {
                    output = "-1";
                }
                else
                {
                    output = std::to_string(queue.back());
                }
            }
            std::cout << output << '\n';
        }
    }

    return 0;
}
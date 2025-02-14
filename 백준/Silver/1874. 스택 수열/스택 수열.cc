/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1874                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1874                           #+#        #+#      #+#    */
/*   Solved: 2025/02/13 23:37:45 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, now = 1;
    std::cin >> n;

    std::vector<int> stack(n);
    std::vector<char> output;
    std::vector<int> input(n);

    for (auto i = 0; i < n; i++)
    {
        std::cin >> input.at(i);
    }
    std::reverse(input.begin(), input.end());

    for (auto i = 0; i < 2 * n; i++)
    {
        if (input.back() + 1 > now)
        {
            stack.push_back(now++);
            output.push_back('+');
        }
        else if (input.back() == stack.back())
        {
            stack.pop_back();
            output.push_back('-');
            input.pop_back();
        }
        else
        {
            std::cout << "NO";
            output.clear();
            break;
        }
    }

    for (auto i = output.begin(); i != output.end(); i++)
    {
        std::cout << *i << '\n';
    }

    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1436                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1436                           #+#        #+#      #+#    */
/*   Solved: 2025/02/12 21:16:21 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    short n, digitB = 0;
    int a = 0, b = 0;
    std::string before = "", after = "", goalB = "";
    bool turnA = true;

    std::cin >> n;
    if (n != 1)
    {
        for (auto i = 1; i < n; i++)
        {
            if (turnA)
            {
                if (a++ % 10 == 5)
                {
                    turnA = false;
                    std::string temp = std::to_string(a);
                    std::reverse(temp.begin(), temp.end());
                    for (auto j = temp.begin(); j != temp.end(); j++)
                    {
                        if (*j == '6')
                        {
                            digitB++;
                            goalB += '9';
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
            else
            {
                if (b++ == std::stoi(goalB))
                {
                    turnA = true;
                    goalB = "";
                    digitB = 0;
                    b = 0;
                    a++;
                }
            }
        }
        before = std::to_string(a);
        for (auto i = 0; i < digitB; i++)
        {
            before.pop_back();
        }
        after = digitB == 0 ? "" : std::to_string(b);
        while (digitB > after.length())
        {
            after = '0' + after;
        }
    }

    std::cout << before << 666 << after;

    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2920                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2920                           #+#        #+#      #+#    */
/*   Solved: 2025/02/05 19:46:34 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    short input, temp;
    std::cin >> input;
    if (input == 1)
    {
        for (short i = 1; i < 8; i++)
        {
            std::cin >> temp;
            if (temp - input == 1)
            {
                input = temp;
            }
            else
            {
                std::cout << "mixed";
                break;
            }

            if (i == 7)
            {
                std::cout << "ascending";
            }
        }
    }
    else if (input == 8)
    {
        for (short i = 1; i < 8; i++)
        {
            std::cin >> temp;
            if (input - temp == 1)
            {
                input = temp;
            }
            else
            {
                std::cout << "mixed";
                break;
            }

            if (i == 7)
            {
                std::cout << "descending";
            }
        }
    }
    else
    {
        std::cout << "mixed";
    }

    return 0;
}
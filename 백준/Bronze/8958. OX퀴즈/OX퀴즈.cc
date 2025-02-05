/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 8958                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/8958                           #+#        #+#      #+#    */
/*   Solved: 2025/02/05 19:46:48 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    short t, output = 0, count = 0;
    std::string input;

    std::cin >> t;

    for (short i = 0; i < t; i++)
    {
        std::cin >> input;
        for (short j = 0; j < input.length(); j++)
        {
            if (input.at(j) == 'O')
            {
                output += ++count;
            }
            else
            {
                count = 0;
            }
        }
        std::cout << output << '\n';
        output = 0;
        count = 0;
    }
    return 0;
}
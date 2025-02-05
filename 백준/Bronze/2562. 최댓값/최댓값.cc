/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2562                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2562                           #+#        #+#      #+#    */
/*   Solved: 2025/02/05 11:20:32 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    short count, index, max, input;
    count = 0;
    max = 0;
    while (true)
    {
        if (std::cin.eof())
            break;
        std::cin >> input;
        count++;
        if (input > max)
        {
            index = count;
            max = input;
        }
    }
    std::cout << max << '\n'
              << index << '\n';
    return 0;
}
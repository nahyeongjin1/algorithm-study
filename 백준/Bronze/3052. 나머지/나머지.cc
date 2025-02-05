/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 3052                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/3052                           #+#        #+#      #+#    */
/*   Solved: 2025/02/05 19:46:41 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    short input[10];
    short temp;
    short output = 10;

    for (short i = 0; i < 10; i++)
    {
        std::cin >> temp;
        input[i] = temp % 42;

        for (short j = 0; j < i; j++)
        {
            if (input[j] == input[i])
            {
                output -= 1;
                break;
            }
        }
    }
    std::cout << output;
    return 0;
}
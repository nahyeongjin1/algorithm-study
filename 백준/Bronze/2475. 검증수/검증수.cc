/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2475                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2475                           #+#        #+#      #+#    */
/*   Solved: 2025/02/05 19:46:13 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    short input, output = 0;
    for (short i = 0; i < 5; i++)
    {
        std::cin >> input;
        output += input * input;
    }
    std::cout << output % 10;

    return 0;
}
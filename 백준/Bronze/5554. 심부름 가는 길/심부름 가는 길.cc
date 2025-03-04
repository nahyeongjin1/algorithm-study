/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 5554                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/5554                           #+#        #+#      #+#    */
/*   Solved: 2025/03/04 20:54:41 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    uint32_t input, second_sum = 0;
    for (uint16_t i = 0; i < 4; i++)
    {
        std::cin >> input;
        second_sum += input;
    }
    std::cout << second_sum / 60 << '\n'
              << second_sum % 60 << '\n';

    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 26209                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/26209                          #+#        #+#      #+#    */
/*   Solved: 2025/02/07 21:54:17 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    short input;
    char output = 'S';
    for (auto i = 0; i < 8; i++)
    {
        std::cin >> input;
        if (input == 9)
        {
            output = 'F';
            break;
        }
    }
    std::cout << output;
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2438                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2438                           #+#        #+#      #+#    */
/*   Solved: 2025/02/04 22:04:09 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    short n;

    std::cin >> n;

    for (short i = 1; i <= n; i++)
    {
        for (short j = 0; j < i; j++)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }

    return 0;
}
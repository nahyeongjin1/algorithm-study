/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10952                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10952                          #+#        #+#      #+#    */
/*   Solved: 2025/02/04 22:15:38 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    while (true)
    {
        short a, b;
        std::cin >> a >> b;
        if (a == 0 && b == 0)
        {
            break;
        }
        std::cout << a + b << '\n';
    }

    return 0;
}
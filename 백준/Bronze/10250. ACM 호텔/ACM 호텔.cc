/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10250                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10250                          #+#        #+#      #+#    */
/*   Solved: 2025/02/05 19:47:02 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    size_t t;
    short h, w, n, x, y;
    std::cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        std::cin >> h >> w >> n;
        y = n % h;
        x = n / h + 1;
        if (y == 0)
        {
            y = h;
            x -= 1;
        }
        std::cout << y;
        if (x / 10 == 0)
            std::cout << '0' << x;
        else
            std::cout << x;
        std::cout << '\n';
    }
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4153                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4153                           #+#        #+#      #+#    */
/*   Solved: 2025/02/16 17:47:25 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    while (true)
    {
        long long int a, b, c;
        std::string output;
        std::cin >> a >> b >> c;
        if (a == 0 and b == 0 and c == 0)
        {
            break;
        }
        else if (a == 0 or b == 0 or c == 0)
        {
            output = "wrong";
        }
        else
        {
            if (a > c)
            {
                std::swap(a, c);
            }
            if (b > c)
            {
                std::swap(b, c);
            }
            output = (a * a + b * b == c * c) ? "right" : "wrong";
        }
        std::cout << output << '\n';
    }

    return 0;
}
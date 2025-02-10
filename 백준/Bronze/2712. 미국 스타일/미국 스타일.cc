/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2712                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2712                           #+#        #+#      #+#    */
/*   Solved: 2025/02/10 23:39:14 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    short t;
    long double value, output;
    std::string unit;

    std::cin >> t;
    for (auto i = 0; i < t; i++)
    {
        std::cin >> value >> unit;
        if (unit == "kg")
        {
            output = 2.2046 * value;
            unit = "lb";
        }
        else if (unit == "lb")
        {
            output = 0.4536 * value;
            unit = "kg";
        }
        else if (unit == "l")
        {
            output = 0.2642 * value;
            unit = "g";
        }
        else
        {
            output = 3.7854 * value;
            unit = "l";
        }
        std::cout << std::fixed;
        std::cout.precision(4);
        std::cout << output << ' ' << unit << '\n';
    }
    return 0;
}
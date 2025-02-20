/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9095                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9095                           #+#        #+#      #+#    */
/*   Solved: 2025/02/20 21:23:48 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

long int factorial(short input)
{
    long int result = 1;
    for (auto i = 2; i <= input; i++)
    {
        result *= i;
    }
    return result;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    std::cin >> t;
    for (auto i = 0; i < t; i++)
    {
        long int output = 0;
        short n;
        std::cin >> n;
        for (auto three = 0; three <= n / 3; three++)
        {
            for (auto two = 0; two <= (n - 3 * three) / 2; two++)
            {
                short one = n - 3 * three - 2 * two;
                output += factorial(three + two + one) / (factorial(three) * factorial(two) * factorial(one));
            }
        }
        std::cout << output << '\n';
    }

    return 0;
}

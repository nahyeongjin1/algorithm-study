/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 6064                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/6064                           #+#        #+#      #+#    */
/*   Solved: 2025/02/26 16:32:18 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

typedef unsigned short us;
typedef unsigned int ui;

us gcd(const int &m, const int &n)
{
    us result = 1;
    us min = std::min(m, n);
    for (us div = 2; div <= min; div++)
    {
        if (m % div == 0 && n % div == 0)
        {
            result = div;
        }
    }
    return result;
}

ui lcm(const int &m, const int &n)
{
    return (ui(m) * ui(n)) / gcd(m, n);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    us t;
    std::cin >> t;
    for (auto i = 0; i < t; i++)
    {
        int m, n; // 1 <= m, n <= 40,000
        int x;    // 1 <= x <= m
        int y;    // 1 <= y <= n

        std::cin >> m >> n >> x >> y;
        int y_prime = x - m;

        ui max = lcm(m, n);
        ui j;
        for (j = x; j <= max; j += m)
        {
            y_prime += m;
            y_prime %= n;
            y_prime = (y_prime == 0) ? n : y_prime;
            if (y_prime == y)
            {
                break;
            }
        }
        if (j != max + x)
        {
            std::cout << j << '\n';
        }
        else
        {
            std::cout << -1 << '\n';
        }
    }

    return 0;
}
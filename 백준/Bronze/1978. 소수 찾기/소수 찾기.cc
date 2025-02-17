/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1978                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1978                           #+#        #+#      #+#    */
/*   Solved: 2025/02/17 18:21:23 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int find_prime(int n)
{
    if (n == 1)
    {
        return 0;
    }
    for (int div = 2; div * div <= n; div++)
    {
        if (n % div == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    short n, input, output = 0;
    std::cin >> n;
    for (auto i = 0; i < n; i++)
    {
        std::cin >> input;
        output += find_prime(input);
    }
    std::cout << output;

    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1929                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1929                           #+#        #+#      #+#    */
/*   Solved: 2025/02/17 21:50:57 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

void print_prime_in_range(int m, int n)
{
    std::vector<int> result;
    m = (m == 1) ? 2 : m;

    for (int prime = m; prime <= n; prime++)
    {
        bool isBreak = false;
        for (int div = 2; div * div <= prime; div++)
        {
            if (prime % div == 0)
            {
                isBreak = true;
                break;
            }
        }
        if (!isBreak)
        {
            std::cout << prime << '\n';
        }
    }

    return;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int m, n;
    std::cin >> m >> n;

    print_prime_in_range(m, n);

    return 0;
}
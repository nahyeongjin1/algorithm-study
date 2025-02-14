/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 30802                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/30802                          #+#        #+#      #+#    */
/*   Solved: 2025/02/14 22:24:14 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    long long output = 0;
    const short SIZE = 6;
    std::vector<int> shirts(SIZE);
    int t, p;

    std::cin >> n;
    for (auto i = 0; i < SIZE; i++)
    {
        std::cin >> shirts.at(i);
    }
    std::cin >> t >> p;

    for (auto i = 0; i < SIZE; i++)
    {
        output += shirts.at(i) / t;
        output += (shirts.at(i) % t == 0) ? 0 : 1;
    }

    std::cout << output << '\n';
    std::cout << n / p << ' ' << n % p;
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9461                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9461                           #+#        #+#      #+#    */
/*   Solved: 2025/02/20 21:23:37 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    std::cin >> t;
    for (auto i = 0; i < t; i++)
    {
        short n;
        std::cin >> n;
        std::vector<unsigned long long int> p(n + 1, 0);
        if (n >= 1)
        {
            p.at(1) = 1;
        }
        if (n >= 2)
        {
            p.at(2) = 1;
        }
        if (n >= 3)
        {
            p.at(3) = 1;
        }
        if (n >= 4)
        {
            p.at(4) = 2;
        }
        if (n >= 5)
        {
            p.at(5) = 2;
        }
        for (auto j = 6; j <= n; j++)
        {
            p.at(j) = p.at(j - 1) + p.at(j - 5);
        }
        std::cout << p.back() << '\n';
    }

    return 0;
}
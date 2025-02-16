/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2798                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2798                           #+#        #+#      #+#    */
/*   Solved: 2025/02/16 21:27:06 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    short n;
    int m, sum, max = 0;

    std::cin >> n >> m;
    std::vector<int> vec(n);

    for (auto i = 0; i < n; i++)
    {
        std::cin >> vec.at(i);
    }

    for (auto i = 0; i < n - 2; i++)
    {
        for (auto j = i + 1; j < n - 1; j++)
        {
            for (auto k = j + 1; k < n; k++)
            {
                sum = vec.at(i) + vec.at(j) + vec.at(k);
                if (sum > max and sum <= m)
                {
                    max = sum;
                    if (max == m)
                    {
                        break;
                    }
                }
            }
            if (max == m)
            {
                break;
            }
        }
        if (max == m)
        {
            break;
        }
    }

    std::cout << max;

    return 0;
}
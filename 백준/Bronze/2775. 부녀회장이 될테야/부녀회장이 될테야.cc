/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2775                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2775                           #+#        #+#      #+#    */
/*   Solved: 2025/02/16 22:35:49 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using std::vector;

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    long long int output = 0;
    std::cin >> t;
    for (auto i = 0; i < t; i++)
    {
        short k, n;
        std::cin >> k >> n;

        vector<vector<long long int>> residents(k + 1, vector<long long int>(n));

        for (auto j = 0; j < n; j++)
        {
            residents.at(0).at(j) = j + 1;
        }

        for (auto j = 0; j <= k; j++)
        {
            residents.at(j).at(0) = 1;
        }

        for (auto j = 1; j < n; j++)
        {
            for (auto u = 1; u <= k; u++)
            {
                residents.at(u).at(j) = residents.at(u - 1).at(j) + residents.at(u).at(j - 1);
            }
        }

        std::cout << residents.at(k).at(n - 1) << '\n';
    }

    return 0;
}

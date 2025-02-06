/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10810                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: skgudwls <boj.kr/u/skgudwls>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10810                          #+#        #+#      #+#    */
/*   Solved: 2025/02/06 20:50:51 by skgudwls      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    short n, m, i, j, k;
    std::vector<short> bagooni;

    std::cin >> n >> m;
    for (short t = 0; t < n; t++)
    {
        bagooni.push_back(0);
    }
    for (short t = 0; t < m; t++)
    {
        std::cin >> i >> j >> k;
        for (short u = i - 1; u <= j - 1; u++)
        {
            bagooni.at(u) = k;
        }
    }
    for (short t = 0; t < bagooni.size(); t++)
    {
        std::cout << bagooni.at(t) << ' ';
    }
    return 0;
}